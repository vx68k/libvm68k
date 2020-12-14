// runtime_register.cpp
// Copyright (C) 2020 Kaz Nishimura
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

#include <bits/vm68k/register_file.h>

using std::move;
using std::size_t;
using namespace vm68k;

register_file::register_file()
{
    // Nothing to do.
}

register_file::register_file(const register_file &other)
:
    _d {other._d},
    _a {other._a}
{
    // Nothing to do.
}

register_file::register_file(register_file &&other)
:
    _d {move(other._d)},
    _a {move(other._a)}
{
    // Nothing to do.
}

register_file::~register_file()
{
    // Nothing to do.
}

data_register &register_file::d(const size_t regno)
{
    return _d[regno];
}

const data_register &register_file::d(const size_t regno) const
{
    return _d[regno];
}

address_register &register_file::a(const size_t regno)
{
    return _a[regno];
}

const address_register &register_file::a(const size_t regno) const
{
    return _a[regno];
}
