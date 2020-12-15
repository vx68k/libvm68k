// <bits/vm68k/register_file.h>
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

#ifndef _VM68K_REGISTER_FILE_H
#define _VM68K_REGISTER_FILE_H 1

#include <bits/vm68kdef.h>
#include <vm68k/data>
#include <array>
#include <utility>
#include <cstdint>

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
}

#endif
