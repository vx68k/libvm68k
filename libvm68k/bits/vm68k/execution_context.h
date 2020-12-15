// <bits/vm68k/execution_context.h>
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

#ifndef _VM68K_EXECUTION_CONTEXT_H
#define _VM68K_EXECUTION_CONTEXT_H 1

#include <bits/vm68kdef.h>
#include <vm68k/memory>
#include <vm68k/data>
#include <array>
#include <memory>
#include <cstddef>

namespace vm68k
{
    /**
     * Data registers.
     */
    class _VM68K_PUBLIC data_register
    {
    private:
        long_word::uint_type _value;

    public:
        data_register &operator =(const long_word value)
        {
            _value = value.to_uint();
            return *this;
        }

        data_register &operator =(const word value)
        {
            auto unchanged = _value & 0xffff0000U;
            _value = unchanged | value.to_uint();
            return *this;
        }

        data_register &operator =(const byte value)
        {
            auto unchanged = _value & 0xffffff00U;
            _value = unchanged | value.to_uint();
            return *this;
        }

    public:
        /**
         * Converts the register value to a long word.
         */
        operator long_word() const noexcept
        {
            return long_word(_value);
        }

        /**
         * Converts the register value to a word.
         */
        operator word() const noexcept
        {
            return word(_value);
        }

        /**
         * Converts the register value to a byte.
         */
        operator byte() const noexcept
        {
            return byte(_value);
        }
    };

    /**
     * Address registers.
     */
    class _VM68K_PUBLIC address_register
    {
    private:
        long_word::uint_type _value;

    public:
        address_register &operator =(const long_word value)
        {
            _value = value.to_int();
            return *this;
        }

        address_register &operator =(const word value)
        {
            // Word assignments shall be sign-extended.
            _value = value.to_int();
            return *this;
        }

    public:
        /**
         * Converts the register value to a long word.
         */
        operator long_word() const noexcept
        {
            return long_word(_value);
        }

        /**
         * Converts the register value to a word.
         */
        operator word() const noexcept
        {
            return word(_value);
        }
    };

    /*
     * Execution contexts.
     */
    class _VM68K_PUBLIC execution_context
    {
    public:
        /**
         * Number of the data registers.
         */
        static const std::size_t DATA_REGISTER_MAX = 8;

        /**
         * Number of the address registers.
         */
        static const std::size_t ADDRESS_REGISTER_MAX = 8;

    private:
        std::shared_ptr<memory_map> _memory;

    private:
        /**
         * Array of the data registers.
         */
        std::array<data_register, DATA_REGISTER_MAX> _d;

        /**
         * Array of the address registers.
         */
        std::array<address_register, ADDRESS_REGISTER_MAX> _a;

    private:
        long_word _pc;

    public:
        execution_context(const std::shared_ptr<memory_map> &memory,
            long_word pc);

        execution_context(std::shared_ptr<memory_map> &&memory,
            long_word pc);

        /**
         * Copy constructor.
         */
        execution_context(const execution_context &other);

        /**
         * Move constructor.
         */
        execution_context(execution_context &&other);

    public:
        virtual ~execution_context();

    public:
        /**
         * Copy assignment operator.
         */
        execution_context &operator =(const execution_context &other);

        /**
         * Move assignment operator.
         */
        execution_context &operator =(execution_context &&other);

    public:
        auto memory() const -> const std::shared_ptr<memory_map> &
        {
            return _memory;
        }

    public:
        /**
         * Returns a reference to a data register.
         */
        data_register &d(std::size_t regno);

        /**
         * Returns a const reference to a data register.
         */
        const data_register &d(std::size_t regno) const;

    public:
        /**
         * Returns a reference to an address register.
         */
        address_register &a(std::size_t regno);

        /**
         * Returns a const reference to an address register.
         */
        const address_register &a(std::size_t regno) const;

    public:
        long_word pc() const;

    public:
        void set_pc(long_word pc);
    };
}

#endif
