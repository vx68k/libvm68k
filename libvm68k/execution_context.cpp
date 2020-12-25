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

#include <utility>
#include <cassert>

using std::move;
using std::shared_ptr;
using std::swap;
using namespace vm68k;


// Implementation of class execution_context.

execution_context::execution_context(const shared_ptr<memory_map> &memory)
:
    _memory {memory}
{
    // Nothing to do.
}

execution_context::execution_context(shared_ptr<memory_map> &&memory) noexcept
:
    _memory {move(memory)}
{
    // Nothing to do.
}

execution_context::execution_context(const execution_context &other)
:
    _memory {other._memory},
    _d {other._d},
    _a {other._a},
    _pc {other._pc}
{
    // Nothing to do.
}

execution_context::execution_context(execution_context &&other) noexcept
:
    _memory {move(other._memory)},
    _d {move(other._d)},
    _a {move(other._a)},
    _pc {move(other._pc)}
{
    // Nothing to do.
}

execution_context::~execution_context()
{
    // Nothing to do.
}

execution_context &execution_context::operator =(const execution_context &other)
{
    if (this != &other) {
        _memory = other._memory;
        _d = other._d;
        _a = other._a;
        _pc = other._pc;
    }
    return *this;
}

void execution_context::swap(execution_context &other) noexcept
{
    if (this != &other) {
        ::swap(_memory, other._memory);
        ::swap(_d, other._d);
        ::swap(_a, other._a);
        ::swap(_pc, other._pc);
    }
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
