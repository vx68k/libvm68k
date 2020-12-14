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
        long_word _value;

    public:
        data_register &operator =(const long_word value)
        {
            _value = value;
            return *this;
        }

        data_register &operator =(const word value)
        {
            auto preserved = _value.to_uint() & 0xffff0000U;
            _value = long_word(preserved | value.to_uint());
            return *this;
        }

        data_register &operator =(const byte value)
        {
            auto preserved = _value.to_uint() & 0xffffff00U;
            _value = long_word(preserved | value.to_uint());
            return *this;
        }

    public:
        operator long_word() const noexcept
        {
            return _value;
        }
    };

    /**
     * Address registers.
     */
    class _VM68K_PUBLIC address_register
    {
    private:
        long_word _value;

    public:
        address_register &operator =(const long_word value)
        {
            _value = value;
            return *this;
        }

    public:
        operator long_word() const noexcept
        {
            return _value;
        }
    };

    /**
     * Register files.
     */
    class _VM68K_PUBLIC register_file
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
        // Array of the data registers.
        std::array<data_register, DATA_REGISTER_MAX> _d;

        // Array of the address registers.
        std::array<address_register, ADDRESS_REGISTER_MAX> _a;

    public:
        register_file();

        register_file(const register_file &other);

        register_file(register_file &&other);

    public:
        virtual ~register_file();

    public:
        long_word d(std::size_t regno) const;

        void set_d(std::size_t regno, long_word value);

        void set_d(std::size_t regno, word value);

        void set_d(std::size_t regno, byte);

    public:
        long_word a(std::size_t regno) const;

        void set_a(std::size_t regno, long_word value);

        void set_a(std::size_t regno, word value)
        {
            set_a(regno, long_word(value.to_int()));
        }
    };
}

#endif
