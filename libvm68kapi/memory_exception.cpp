// memory_exception.cpp
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

#include <bits/vm68k/memory_exception.h>

using namespace vm68k;


// Implementation of the memory exceptions.

memory_exception::memory_exception(const memory_map::mode mode,
    const address_type fault_address) noexcept
:
    _mode {mode},
    _fault_address {fault_address}
{
    // Nothing to do.
}

memory_exception::memory_exception(const memory_exception &other) noexcept
:
    exception(other),
    _mode {other._mode},
    _fault_address {other._fault_address}
{
    // Nothing to do.
}

memory_exception &memory_exception::operator =(const memory_exception &other) noexcept
{
    if (this != &other) {
        exception::operator =(other);
        _fault_address = other._fault_address;
    }
    return *this;
}

memory_exception::~memory_exception()
{
    // Nothing to do.
}

const char *memory_exception::what() const noexcept
{
    return "vm68k::memory_exception";
}


// Implementation of the bus errors.

const char *bus_error::what() const noexcept
{
    return "vm68k::bus_error";
}


// Implementation of the address errors.

const char *address_error::what() const noexcept
{
    return "vm68k::address_error";
}
