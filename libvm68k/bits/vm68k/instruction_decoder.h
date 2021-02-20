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
#include <bits/vm68k/execution_context.h>
#include <vm68k/data>
#include <array>
#include <memory>

namespace vm68k
{
    /**
     * Instruction decoders.
     */
    class _VM68K_PUBLIC instruction_decoder
    {
    public:

        /**
         * Base class for instructions.
         */
        class _VM68K_PUBLIC instruction
        {
        protected:

            // Constructors.

            instruction() = default;

            instruction(const instruction &) = default;

        public:

            // Destructor.

            virtual ~instruction() = default;


            /**
             * Decodes the instruction into an executor.
             *
             * @param code the operation code of the instruction
             * @param c the execution context from which the instruction was fetched
             * @param e an executor
             */
            virtual void decode(word code, execution_context &c, executor &e) = 0;
        };

    private:

        std::array<std::shared_ptr<instruction>, 0x10000U> _instructions;

    public:

        // Constructors.

        instruction_decoder();


        // Destructor.

        virtual ~instruction_decoder();


        long_word decode_instruction(execution_context &c, executor &e) const;
    };
}

#endif
