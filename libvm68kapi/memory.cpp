// memory.cpp
// Copyright (C) 2012-2019 Kaz Nishimura
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
#if __BORLANDC__
#pragma hdrstop
#endif

#define _VM68K_MEMORY_IMPLEMENTATION 1
#include <bits/vm68k/memory.h>

#if __BORLANDC__
#pragma package(smart_init)
#endif

using namespace vm68k;

memory::memory()
{
}

memory::~memory()
{
}

// Class 'read_write_memory' implementation.

std::unique_ptr<read_write_memory::byte_type []>
read_write_memory::allocate(const size_type size)
{
    return std::unique_ptr<byte_type []>(new byte_type [size]);
}

read_write_memory::read_write_memory(const size_type size)
    : _size(size), _data(allocate(size))
{
}

read_write_memory::~read_write_memory()
{
}

memory::size_type read_write_memory::size() const noexcept
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
}

void read_write_memory::check_write_access(const mode, const address_type,
    const size_type)
{
}

memory_map::memory_map()
{
}

memory_map::~memory_map()
{
}

/*
 * memory_exception
 */

memory_exception::memory_exception(memory_map::address_type address)
        noexcept {
    _error_address = address;
}

const char *memory_exception::what() const noexcept {
    return "vm68k::memory_exception";
}

/*
 * bus_error
 */

bus_error::bus_error(memory_map::address_type address) noexcept
        : inherited(address) {
}

bus_error::bus_error(const bus_error &x) noexcept
        : memory_exception(x) {
}

bus_error &bus_error::operator =(const bus_error &x) noexcept {
    *static_cast<memory_exception *>(this) = x;
    return *this;
}

const char *bus_error::what() const noexcept {
    return "vm68k::bus_error";
}

/*
 * address_error
 */

address_error::address_error(memory_map::address_type address) noexcept
        : inherited(address) {
}

address_error::address_error(const address_error &x) noexcept
        : memory_exception(x) {
}

address_error &address_error::operator =(const address_error &x) noexcept {
    *static_cast<memory_exception *>(this) = x;
    return *this;
}

const char *address_error::what() const noexcept {
    return "vm68k::address_error";
}
