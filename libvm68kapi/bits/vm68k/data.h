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

#include <utility>
#include <cstdint>
#include <cstddef>
#include <bits/vm68kapi.h>

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
        /// Returns the size of a `byte` value, which is always 1.
        static constexpr std::size_t size() noexcept
        {
            return 1U;
        }

    public:
        byte() noexcept = default;

        constexpr explicit byte(const std::uint8_t value) noexcept
        :
            _value {value}
        {
            // Nothing to do.
        }

    public:
        /**
         * Swap the content with another.
         */
        void swap(byte &other) noexcept
        {
            std::swap(_value, other._value);
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

        template<class Iterator>
        Iterator serialize(const Iterator output) const
        {
            auto i = output;
            *(i++) = _value;
            return i;
        }

        template<class Iterator>
        Iterator deserialize(const Iterator input)
        {
            auto i = input;
            _value = *(i++);
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
        /// Returns the size of a `word` value, which is always 2.
        static constexpr std::size_t size() noexcept
        {
            return 2U;
        }

    public:
        word() noexcept = default;

        constexpr explicit word(const std::uint16_t value) noexcept
        :
            _value {value}
        {
            // Nothing to do.
        }

    public:
        /**
         * Swap the content with another.
         */
        void swap(word &other) noexcept
        {
            std::swap(_value, other._value);
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

        template<class Iterator>
        Iterator serialize(const Iterator output) const
        {
            auto i = output;
            *(i++) = std::uint8_t(_value >> 8);
            *(i++) = std::uint8_t(_value);
            return i;
        }

        template<class Iterator>
        Iterator deserialize(const Iterator input)
        {
            auto i = input;
            _value  = std::uint8_t(*(i++)) << 8;
            _value |= std::uint8_t(*(i++));
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
        /// Returns the size of a `long_word` value, which is always 4.
        static constexpr std::size_t size() noexcept
        {
            return 4U;
        }

    public:
        long_word() noexcept = default;

        constexpr explicit long_word(const std::uint32_t value) noexcept
        :
            _value {value}
        {
            // Nothing to do.
        }

    public:
        /**
         * Swap the content with another.
         */
        void swap(long_word &other) noexcept
        {
            std::swap(_value, other._value);
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

        template<class Iterator>
        Iterator serialize(const Iterator output) const
        {
            auto i = output;
            *(i++) = std::uint8_t(_value >> 24);
            *(i++) = std::uint8_t(_value >> 16);
            *(i++) = std::uint8_t(_value >> 8);
            *(i++) = std::uint8_t(_value);
            return i;
        }

        template<class Iterator>
        Iterator deserialize(const Iterator input)
        {
            auto i = input;
            _value  = std::uint8_t(*(i++)) << 24;
            _value |= std::uint8_t(*(i++)) << 16;
            _value |= std::uint8_t(*(i++)) << 8;
            _value |= std::uint8_t(*(i++));
            return i;
        }
    };
}

// Specializations.

template<>
inline void std::swap(vm68k::byte &x, vm68k::byte &y) noexcept
{
    x.swap(y);
}

template<>
inline void std::swap(vm68k::word &x, vm68k::word &y) noexcept
{
    x.swap(y);
}

template<>
inline void std::swap(vm68k::long_word &x, vm68k::long_word &y) noexcept
{
    x.swap(y);
}

#endif
