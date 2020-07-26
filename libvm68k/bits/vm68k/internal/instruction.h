// <bits/vm68k/internal/instruction.h>
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

#ifndef _VM68K_INTERNAL_INSTRUCTION_H
#define _VM68K_INTERNAL_INSTRUCTION_H 1

#include <bits/vm68k/internal/register.h>
#include <vm68k/instruction>
#include <memory>
#include <utility>

namespace vm68k
{
    /*
     * Runtime execution contexts.
     */
    class _VM68K_PUBLIC runtime_execution_context: public execution_context
    {
    private:
        std::shared_ptr<memory_map> _memory;

    private:
        runtime_register_file _registers;

    private:
        long_word _pc;

    public:
        runtime_execution_context(const std::shared_ptr<memory_map> &memory,
            long_word pc);

        runtime_execution_context(std::shared_ptr<memory_map> &&memory,
            long_word pc);

    public:
        virtual ~runtime_execution_context();

    public:
        auto memory() const -> std::shared_ptr<memory_map> final override
        {
            return _memory;
        }

    public:
        register_file &registers() final override
        {
            return _registers;
        }

    public:
        long_word pc() const override;

    public:
        void set_pc(long_word pc) override;
    };
}

#endif
