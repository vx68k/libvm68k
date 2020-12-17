// instruction_decoder.cpp
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

#include <bits/vm68k/instruction_decoder.h>

#include <utility>

using std::move;
using std::shared_ptr;
using namespace vm68k;

instruction_decoder::instruction_decoder(const shared_ptr<memory_map> &memory)
:
    _memory {memory}
{
    // Nothing to do.
}

instruction_decoder::instruction_decoder(shared_ptr<memory_map> &&memory)
:
    _memory {move(memory)}
{
    // Nothing to do.
}

instruction_decoder::~instruction_decoder()
{
    // Nothing to do.
}

long_word instruction_decoder::decode(long_word pc, executor &e) const
{
    // TODO: implement this function.
    return pc;
}
