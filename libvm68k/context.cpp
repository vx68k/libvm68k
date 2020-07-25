// context.cpp
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
#if __BORLANDC__
#pragma hdrstop
#endif

#include <bits/vm68k/internal/instruction.h>

using std::shared_ptr;
using namespace vm68k;

#if __BORLANDC__
#pragma package(smart_init)
#endif

runtime_execution_context::runtime_execution_context(
    const shared_ptr<memory_map> &memory, const long_word pc)
:
    execution_context(memory),
    _pc {pc}
{
    // Nothing to do.
}

runtime_execution_context::~runtime_execution_context()
{
    // Nothing to do.
}

long_word runtime_execution_context::pc() const
{
    return _pc;
}

void runtime_execution_context::set_pc(const long_word pc)
{
    _pc = pc;
}
