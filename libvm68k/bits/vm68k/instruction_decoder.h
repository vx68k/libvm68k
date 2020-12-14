// <bits/vm68k/instruction_decoder.h>
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

#include <bits/vm68k/executor.h>
#include <vm68k/data>
#include <array>
#include <memory>

namespace vm68k
{
    class _VM68K_PUBLIC instruction_decoder
    {
    public:
        class _VM68K_PUBLIC instruction
        {
        protected:
            instruction() = default;

            instruction(const instruction &) = default;

        public:
            virtual ~instruction() = default;
        };

    private:
        std::array<std::shared_ptr<instruction>, 0x10000> _instructions;

    public:
        virtual ~instruction_decoder();

    public:
        long_word decode(long_word pc, executor &e) const;
    };
}

#endif