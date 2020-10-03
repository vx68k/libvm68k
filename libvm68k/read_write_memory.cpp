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

#include <bits/vm68k/read_write_memory.h>

#if HAVE_SYS_MMAN_H
#include <sys/mman.h>
#endif
#include <system_error>
#include <cerrno>

using std::declare_no_pointers;
using std::generic_category;
using std::size_t;
using std::system_error;
using std::undeclare_no_pointers;
using std::unique_ptr;
using namespace vm68k;


// Implementation of the read-write memory objects.

auto read_write_memory::allocate_bytes(const size_t size)
    -> unique_ptr<byte_type [], bytes_delete>
{
    auto bytes = static_cast<byte_type *>(
        mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0));
    if (bytes == nullptr) {
        throw system_error(errno, generic_category(),
            "could not get an anonymous memory mapping");
    }
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

void read_write_memory::read(const memory_map::mode mode,
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

void read_write_memory::write(const memory_map::mode mode,
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

void read_write_memory::check_read_access(const memory_map::mode,
    const address_type, const size_type)
{
    // Nothing to do.
}

void read_write_memory::check_write_access(const memory_map::mode,
    const address_type, const size_type)
{
    // Nothing to do.
}

void read_write_memory::bytes_delete::operator ()(byte_type *bytes) const
{
    undeclare_no_pointers(reinterpret_cast<char *>(bytes), _size);
    if (munmap(bytes, _size) == -1) {
        throw system_error(errno, generic_category(),
            "could not release the memory mapping");
    }
}
