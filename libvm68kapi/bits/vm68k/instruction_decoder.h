// <bits/vm68k/instruction_decoder.h> -*- C++ -*-
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

#ifndef _VM68K_INSTRUCTION_DECODER_H
#define _VM68K_INSTRUCTION_DECODER_H 1

#include <memory>
#include <bits/vm68k/executor.h>
#include <bits/vm68k/instruction.h>

namespace vm68k
{
    /**
     * Abstract instruction decoders.
     */
    class _VM68KAPI_PUBLIC instruction_decoder
    {
    protected:
        instruction_decoder() = default;

        instruction_decoder(const instruction_decoder &) = default;

        instruction_decoder(instruction_decoder &&) = default;

    public:
        virtual ~instruction_decoder() = default;

    public:
        virtual auto get_instruction(const execution_context &context) const
            -> const std::shared_ptr<instruction> & = 0;

    public:
        virtual long_word decode(long_word pc, executor &e) const = 0;
    };
}

#endif
