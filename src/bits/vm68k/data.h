// <bits/vm68k/data.h>
// Copyright (C) 2012-2019 Kaz Nishimura
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

#ifndef _VM68K_DATA_H
#define _VM68K_DATA_H 1

#include <bits/vm68kcore.h>
#include <type_traits>
#include <limits>
#include <cstdint>

namespace vm68k
{
    class _VM68KCORE_PUBLIC byte
    {
    public:
        using int_type = std::int8_t;
        using uint_type = std::uint8_t;

    private:
        std::uint8_t _value;

    public:
        static constexpr std::size_t size()
        {
            return 1U;
        }

    public:
        constexpr byte() noexcept
        : _value()
        {
        }

        constexpr byte(const std::uint8_t value) noexcept
        : _value(value)
        {
        }

    public:
        constexpr std::int_least8_t to_int() const noexcept
        {
            return std::int8_t(_value);
        }

        constexpr std::uint_least8_t to_uint() const noexcept
        {
            return _value;
        }
    };

    class _VM68KCORE_PUBLIC word
    {
    public:
        using int_type = std::int16_t;
        using uint_type = std::uint16_t;

    private:
        std::uint16_t _value;

    public:
        static constexpr std::size_t size()
        {
            return 2U;
        }

    public:
        constexpr word() noexcept
        : _value()
        {
        }

        constexpr word(const std::uint16_t value) noexcept
        : _value(value)
        {
        }

    public:
        constexpr std::int_least16_t to_int() const noexcept
        {
            return std::int16_t(_value);
        }

        constexpr std::uint_least16_t to_uint() const noexcept
        {
            return _value;
        }
    };

    class _VM68KCORE_PUBLIC long_word
    {
    public:
        using int_type = std::int32_t;
        using uint_type = std::uint32_t;

    private:
        std::uint32_t _value;

    public:
        static constexpr std::size_t size()
        {
            return 4U;
        }

    public:
        constexpr long_word() noexcept
        : _value()
        {
        }

        constexpr long_word(const std::uint32_t value) noexcept
        : _value(value)
        {
        }

    public:
        constexpr std::int_least32_t to_int() const noexcept
        {
            return std::int32_t(_value);
        }

        constexpr std::uint_least32_t to_uint() const noexcept
        {
            return _value;
        }
    };
}

#endif
