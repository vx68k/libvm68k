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

#include <bits/vm68k/internal/register.h>

using namespace vm68k;

runtime_register_file::runtime_register_file()
{
    // TODO: Implement this function.
}

runtime_register_file::~runtime_register_file()
{
    // Nothing to do.
}

long_word runtime_register_file::d(const int regno) const
{
    return long_word(0); // TODO: Implement this function.
}

void runtime_register_file::set_d(const int regno, const long_word value)
{
    // TODO: Implement this funcction.
}

void runtime_register_file::set_d(const int regno, const word value)
{
    // TODO: Implement this funcction.
}

void runtime_register_file::set_d(const int regno, const byte value)
{
    // TODO: Implement this funcction.
}

long_word runtime_register_file::a(const int regno) const
{
    return long_word(0); // TODO: Implement this function.
}

void runtime_register_file::set_a(const int regno, const long_word value)
{
    // TODO: Implement this funcction.
}
