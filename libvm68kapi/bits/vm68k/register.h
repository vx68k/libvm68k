// <bits/vm68k/register.h>
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

#ifndef _VM68K_REGISTER_H
#define _VM68K_REGISTER_H 1

#if !(_VM68K_REGISTER || _LIBVM68KAPI)
#error "internal header <bits/vm68k/register.h> included directly"
#endif

#include <vm68k/data>
#include <bits/vm68kapi.h>
#include <cstddef>

namespace vm68k
{
    /**
     * Abstract class of register files.
     */
    class _VM68KAPI_PUBLIC register_file
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
}

#endif
