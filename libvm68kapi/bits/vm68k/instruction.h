// <bits/vm68k/instruction.h> -*- C++ -*-
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

#ifndef _VM68K_INSTRUCTION_H
#define _VM68K_INSTRUCTION_H 1

#include <vm68k/register>
#include <vm68k/memory>
#include <memory>
#include <bits/vm68kapi.h>

namespace vm68k
{
    /**
     * Abstract execution contexts.
     */
    class _VM68KAPI_PUBLIC execution_context
    {
    protected:
        execution_context() = default;

        execution_context(const execution_context &) = default;

        execution_context(execution_context &&) = default;

    public:
        virtual ~execution_context() = default;

    public:
        virtual auto memory() const -> std::shared_ptr<memory_map> = 0;

    public:
        virtual register_file &registers() = 0;

        const register_file &registers() const
        {
            return const_cast<execution_context *>(this)->registers();
        }

    public:
        virtual long_word pc() const = 0;

        virtual void set_pc(long_word pc) = 0;
    };

    /**
     * Abstruct instructions.
     */
    class _VM68KAPI_PUBLIC instruction
    {
    protected:
        instruction() noexcept = default;

        instruction(const instruction &) noexcept = default;

    public:
        virtual ~instruction() = default;

    public:
        virtual void execute(execution_context &context) const = 0;
    };

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
    };
}

#endif
