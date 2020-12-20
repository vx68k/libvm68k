// read_write_memory.cpp
// Copyright (C) 2012-2020 Kaz Nishimura
//
// This program is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
// more details.
//
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see <http://www.gnu.org/licenses/>.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#if HAVE_CONFIG_H
#include <config.h>
#endif

#if _WIN32
#define WIN32_LEAN_AND_MEAN 1
#include <windows.h>
#endif

#include <bits/vm68k/read_write_memory.h>

#if HAVE_SYS_MMAN_H
#include <sys/mman.h>
#endif
#include <new>
#include <cstdint>

using std::bad_alloc;
using std::declare_no_pointers;
using std::size_t;
using std::uint64_t;
using std::undeclare_no_pointers;
using std::unique_ptr;
using namespace vm68k;


// Implementation of the read-write memory objects.

void read_write_memory::bytes_delete::operator ()(byte_type *bytes) const
{
    undeclare_no_pointers(reinterpret_cast<char *>(bytes), _size);
#if HAVE_SYS_MMAN_H && defined MAP_ANONYMOUS
    munmap(bytes, _size);
#elif _WIN32
    UnmapViewOfFile(bytes);
#else
    delete[] bytes;
#endif
}

auto read_write_memory::allocate_bytes(const size_t size)
    -> unique_ptr<byte_type [], bytes_delete>
{
#if HAVE_SYS_MMAN_H && defined MAP_ANONYMOUS
    auto &&bytes = static_cast<byte_type *>(
        mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS,
            -1, 0));
    if (bytes == nullptr) {
        throw bad_alloc();
    }
#elif _WIN32
    auto &&handle =
        CreateFileMappingA(INVALID_HANDLE_VALUE, nullptr, PAGE_READWRITE,
            (uint64_t)size >> 32, size, nullptr);
    if (handle == nullptr) {
        throw bad_alloc();
    }
    auto &&bytes = static_cast<byte_type *>(
        MapViewOfFile(handle, FILE_MAP_ALL_ACCESS, 0, 0, size));
    CloseHandle(handle); // This handle is no longer needed.
    if (bytes == nullptr) {
        throw bad_alloc();
    }
#else
    auto bytes = new byte_type[size] {};
#endif
    declare_no_pointers(reinterpret_cast<char *>(bytes), size);
    return {bytes, bytes_delete(size)};
}

read_write_memory::read_write_memory(const size_type size)
:
    _size {size},
    _bytes {allocate_bytes(size)}
{
    // Nothing to do here.
}

read_write_memory::~read_write_memory()
{
    // Nothing to do here, but this should be out-of-line.
}

memory_map::size_type read_write_memory::size() const noexcept
{
    return _size;
}

void read_write_memory::relocate(const address_type base_address)
{
    _base_address = base_address;
}

void read_write_memory::read(const access_mode mode,
    const address_type address, size_type n, void *const buffer)
{
    check_read_access(mode, address, n);

    auto offset = address - _base_address;
    // Note OFFSET is unsigned.
    if (offset >= _size) {
        throw bus_error(mode, address);
    }

    auto i = static_cast<unsigned char *>(buffer);
    while (n--) {
        // TODO: The following check should be moved out of loop.
        if (offset >= _size) {
            throw bus_error(mode, _base_address + offset);
        }
        *(i++) = _bytes[offset++];
    }
}

void read_write_memory::write(const access_mode mode,
    const address_type address, size_type n, const void *const buffer)
{
    check_write_access(mode, address, n);

    auto offset = address - _base_address;
    // Note OFFSET is unsigned.
    if (offset >= _size) {
        throw bus_error(mode, address);
    }

    auto i = static_cast<const unsigned char *>(buffer);
    while (n--) {
        // TODO: The following check should be moved out of loop.
        if (offset >= _base_address + _size) {
            throw bus_error(mode, _base_address + offset);
        }
        _bytes[offset++] = *(i++);
    }
}

void read_write_memory::check_read_access(const access_mode,
    const address_type, const size_type)
{
    // Nothing to do.
}

void read_write_memory::check_write_access(const access_mode,
    const address_type, const size_type)
{
    // Nothing to do.
}
