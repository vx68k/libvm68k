// <bits/vm68k/internal/register_file.h>
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

#ifndef _VM68K_INTERNAL_REGISTER_FILE_H
#define _VM68K_INTERNAL_REGISTER_FILE_H 1

#include <vm68k/register>
#include <vm68k/data>
#include <bits/vm68kdef.h>
#include <array>
#include <utility>
#include <cstdint>

namespace vm68k
{
    /**
     * Abstract class of register files.
     */
    class _VM68K_PUBLIC register_file
    {
    public:
        /**
         * Number of the data registers.
         */
        static const std::size_t D_REGISTER_MAX = 8;

        /**
         * Number of the address registers.
         */
        static const std::size_t A_REGISTER_MAX = 8;

    protected:
        register_file() noexcept = default;

        register_file(const register_file &) noexcept = default;

    public:
        virtual ~register_file() = default;

    public:
        virtual long_word d(std::size_t regno) const = 0;

        virtual void set_d(std::size_t regno, long_word value) = 0;

        virtual void set_d(std::size_t regno, word value) = 0;

        virtual void set_d(std::size_t regno, byte value) = 0;

    public:
        virtual long_word a(std::size_t regno) const = 0;

        virtual void set_a(std::size_t regno, long_word value) = 0;

        void set_a(std::size_t regno, word value)
        {
            set_a(regno, long_word(value.to_int()));
        }
    };

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

    class _VM68K_PUBLIC runtime_register_file: public register_file
    {
    private:
        // Array of the data registers.
        std::array<data_register, D_REGISTER_MAX> _d;

        // Array of the address registers.
        std::array<address_register, A_REGISTER_MAX> _a;

    public:
        runtime_register_file();

        runtime_register_file(const runtime_register_file &other);

        runtime_register_file(runtime_register_file &&other);

    public:
        virtual ~runtime_register_file();

    public:
        long_word d(std::size_t regno) const override;

        void set_d(std::size_t regno, long_word value) override;

        void set_d(std::size_t regno, word value) override;

        void set_d(std::size_t regno, byte) override;

    public:
        long_word a(std::size_t regno) const override;

        void set_a(std::size_t regno, long_word value) override;
    };
}

#endif
