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

#include <bits/vm68kapi.h>
#include <cstdint>

namespace vm68k
{
    /// Byte (8-bit-wide) data.
    ///
    /// This type is trivial and standard-layout.
    class _VM68KAPI_PUBLIC byte
    {
    public:
        using int_type = std::int8_t;
        using uint_type = std::uint8_t;

    private:
        std::uint8_t _value;

    public:
        /// Returns the size of a byte, which is 1.
        static constexpr std::size_t size()
        {
            return 1U;
        }

    public:
        byte() = default;

        constexpr byte(const std::uint8_t value) noexcept
            : _value(value)
        {
        }

        byte &operator =(const std::uint8_t value) noexcept
        {
            _value = value;
            return *this;
        }

    public:
        constexpr std::int8_t to_int() const noexcept
        {
            return std::int8_t(_value);
        }

        constexpr std::uint8_t to_uint() const noexcept
        {
            return _value;
        }

        void *serialize(void *const to) const
        {
            auto i = static_cast<unsigned char *>(to);
            *(i++) = _value;
            return i;
        }
    };

    /// Word (16-bit-wide) data.
    ///
    /// This type is trivial and standard-layout.
    class _VM68KAPI_PUBLIC word
    {
    public:
        using int_type = std::int16_t;
        using uint_type = std::uint16_t;

    private:
        std::uint16_t _value;

    public:
        /// Returns the size of a word, which is 2.
        static constexpr std::size_t size()
        {
            return 2U;
        }

    public:
        word() = default;

        constexpr word(const std::uint16_t value) noexcept
            : _value(value)
        {
        }

        word &operator =(const std::uint16_t value) noexcept
        {
            _value = value;
            return *this;
        }

    public:
        constexpr std::int16_t to_int() const noexcept
        {
            return std::int16_t(_value);
        }

        constexpr std::uint16_t to_uint() const noexcept
        {
            return _value;
        }

        void *serialize(void *const to) const
        {
            auto i = static_cast<unsigned char *>(to);
            *(i++) = std::uint8_t(_value >> 8);
            *(i++) = std::uint8_t(_value);
            return i;
        }
    };

    /// Long word (32-bit-wide) data.
    ///
    /// This type is trivial and standard-layout.
    class _VM68KAPI_PUBLIC long_word
    {
    public:
        using int_type = std::int32_t;
        using uint_type = std::uint32_t;

    private:
        std::uint32_t _value;

    public:
        /// Returns the size of a long word, which is 4.
        static constexpr std::size_t size()
        {
            return 4U;
        }

    public:
        long_word() = default;

        constexpr long_word(const std::uint32_t value) noexcept
            : _value(value)
        {
        }

        long_word &operator =(const std::uint32_t value) noexcept
        {
            _value = value;
            return *this;
        }

    public:
        constexpr std::int32_t to_int() const noexcept
        {
            return std::int32_t(_value);
        }

        constexpr std::uint32_t to_uint() const noexcept
        {
            return _value;
        }

        void *serialize(void *const to) const
        {
            auto i = static_cast<unsigned char *>(to);
            *(i++) = std::uint8_t(_value >> 24);
            *(i++) = std::uint8_t(_value >> 16);
            *(i++) = std::uint8_t(_value >> 8);
            *(i++) = std::uint8_t(_value);
            return i;
        }
    };
}

#endif
