// memory.cpp
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

using namespace vm68k;


// Implementation of the read-write memory objects.

std::unique_ptr<read_write_memory::byte_type []>
read_write_memory::allocate(const size_type size)
{
    return std::unique_ptr<byte_type []>(new byte_type [size]);
}

read_write_memory::read_write_memory(const size_type size)
:
    _size {size},
    _data {allocate(size)}
{
    std::declare_no_pointers(reinterpret_cast<char *>(_data.get()), _size);
}

read_write_memory::~read_write_memory()
{
    std::undeclare_no_pointers(reinterpret_cast<char *>(_data.get()), _size);
}

memory_map::size_type read_write_memory::size() const noexcept
{
    return _size;
}

void read_write_memory::read(const mode m, const address_type address,
    const size_type n, void *const bytes)
{
    check_read_access(m, address, n);
}

void read_write_memory::write(const mode m, const address_type address,
    const size_type n, const void *const bytes)
{
    check_write_access(m, address, n);
}

void read_write_memory::check_read_access(const mode, const address_type,
    const size_type)
{
    // Nothing to do.
}

void read_write_memory::check_write_access(const mode, const address_type,
    const size_type)
{
    // Nothing to do.
}
