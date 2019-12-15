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

using namespace vm68k;

#if __BORLANDC__
#pragma package(smart_init)
#endif

memory::~memory()
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
