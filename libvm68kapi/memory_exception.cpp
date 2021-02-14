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


// Implementation of class memory_exception.

memory_exception::memory_exception(const function_code fc,
    const memory_map::address_type address) noexcept
:
    _fc {fc},
    _address {address}
{
    // Nothing to do.
}

memory_exception::memory_exception(const memory_exception &other) noexcept
:
    exception(other),
    _fc {other._fc},
    _address {other._address}
{
    // Nothing to do.
}

memory_exception::~memory_exception()
{
    // Nothing to do.
}

memory_exception &memory_exception::operator =(const memory_exception &other)
    noexcept
{
    exception::operator =(other);
    _fc = other._fc;
    _address = other._address;
    return *this;
}

const char *memory_exception::what() const noexcept
{
    return "vm68k::memory_exception";
}


// Implementation of class bus_error.

bus_error::bus_error(const function_code fc,
    const memory_map::address_type address) noexcept
:
    memory_exception(fc, address)
{
    // Nothing to do.
}

const char *bus_error::what() const noexcept
{
    return "vm68k::bus_error";
}


// Implementation of class address_error.

address_error::address_error(const function_code fc,
    const memory_map::address_type address) noexcept
:
    memory_exception(fc, address)
{
    // Nothing to do.
}

const char *address_error::what() const noexcept
{
    return "vm68k::address_error";
}
