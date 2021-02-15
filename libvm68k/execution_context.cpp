// execution_context.cpp
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

#include <bits/vm68k/execution_context.h>

#include <cassert>

using std::shared_ptr;
using namespace vm68k;

using data_register = execution_context::data_register;
using address_register = execution_context::address_register;


// Implementation of class execution_context.

execution_context::execution_context(const shared_ptr<memory_map> &memory)
:
    _memory {memory}
{
    // Nothing to do.
}

execution_context::~execution_context()
{
    // Nothing to do.
}

data_register &execution_context::d(const size_t regno)
{
    assert(regno < DATA_REGISTER_MAX);
    return _d[regno];
}

const data_register &execution_context::d(const size_t regno) const
{
    assert(regno < DATA_REGISTER_MAX);
    return _d[regno];
}

address_register &execution_context::a(const size_t regno)
{
    assert(regno < ADDRESS_REGISTER_MAX);
    return _a[regno];
}

const address_register &execution_context::a(const size_t regno) const
{
    assert(regno < ADDRESS_REGISTER_MAX);
    return _a[regno];
}

long_word execution_context::pc() const
{
    return _pc;
}

void execution_context::set_pc(const long_word pc)
{
    _pc = pc;
}
