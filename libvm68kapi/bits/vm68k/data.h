// <bits/vm68k/data.h>
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

#ifndef _VM68K_DATA_H
#define _VM68K_DATA_H 1

#include <bits/vm68kapidef.h>
#include <utility>
#include <cstdint>
#include <cstddef>

namespace vm68k
{
    /**
     * Byte data on the VM68000 arthitecture.
     * A byte is 8-bit wide.
     *
     * This type is trivial and standard-layout.
     */
    class byte
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
         * Swaps the value of the object with another one.
         */
        void swap(byte &other) noexcept
        {
            using std::swap;
            swap(_value, other._value);
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

    /**
     * Returns true if and only if two `byte` values are equal to each other.
     *
     * @param x a `byte` value
     * @param y another `byte` value
     * @return true if the two values are equal to each other; false otherwise
     */
    inline constexpr bool operator ==(const byte &x, const byte &y) noexcept
    {
        return x.to_uint() == y.to_uint();
    }

    /**
     * Returns true if and only if two `byte` values are not equal to each other.
     *
     * @param x a `byte` value
     * @param y another `byte` value
     * @return true if the two values are *not* equal to each other; false otherwise
     */
    inline constexpr bool operator !=(const byte &x, const byte &y) noexcept
    {
        return x.to_uint() != y.to_uint();
    }

    /**
     * Returns the sum of two `byte` values.
     */
    inline constexpr byte operator +(const byte &x, const byte &y) noexcept
    {
        return byte(x.to_uint() + y.to_uint());
    }

    /**
     * Returns the difference of two `byte` values.
     */
    inline constexpr byte operator -(const byte &x, const byte &y) noexcept
    {
        return byte(x.to_uint() - y.to_uint());
    }

    inline void swap(byte &x, byte &y) noexcept
    {
        x.swap(y);
    }


    /**
     * Word data on the VM68000 architecture.
     * A word is 16-bit wide.
     *
     * This type is trivial and standard-layout.
     */
    class word
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
         * Swaps the value of the object with another one.
         */
        void swap(word &other) noexcept
        {
            using std::swap;
            swap(_value, other._value);
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

    /**
     * Returns true if and only if two `word` values are equal to each other.
     *
     * @param x a `word` value
     * @param y another `word` value
     * @return true if the two values are equal to each other; false otherwise
     */
    inline constexpr bool operator ==(const word &x, const word &y) noexcept
    {
        return x.to_uint() == y.to_uint();
    }

    /**
     * Returns true if and only if two `word` values are not equal to each other.
     *
     * @param x a `word` value
     * @param y another `word` value
     * @return true if the two values are *not* equal to each other; false otherwise
     */
    inline constexpr bool operator !=(const word &x, const word &y) noexcept
    {
        return x.to_uint() != y.to_uint();
    }

    /**
     * Returns the sum of two `word` values.
     */
    inline constexpr word operator +(const word &x, const word &y) noexcept
    {
        return word(x.to_uint() + y.to_uint());
    }

    /**
     * Returns the difference of two `word` values.
     */
    inline constexpr word operator -(const word &x, const word &y) noexcept
    {
        return word(x.to_uint() - y.to_uint());
    }

    inline void swap(word &x, word &y) noexcept
    {
        x.swap(y);
    }


    /**
     * Long word data on the VM68000 architecture.
     * A long word is 32-bit wide.
     *
     * This type is trivial and standard-layout.
     */
    class long_word
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
         * Swaps the value of the object with another one.
         */
        void swap(long_word &other) noexcept
        {
            using std::swap;
            swap(_value, other._value);
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

    /**
     * Returns true if and only if two `long_word` values are equal to each other.
     *
     * @param x a `long_word` value
     * @param y another `long_word` value
     * @return true if the two values are equal to each other; false otherwise
     */
    inline constexpr bool operator ==(const long_word &x, const long_word &y) noexcept
    {
        return x.to_uint() == y.to_uint();
    }

    /**
     * Returns true if and only if two `long_word` values are not equal to each other.
     *
     * @param x a `long_word` value
     * @param y another `long_word` value
     * @return true if the two values are *not* equal to each other; false otherwise
     */
    inline constexpr bool operator !=(const long_word &x, const long_word &y) noexcept
    {
        return x.to_uint() != y.to_uint();
    }

    /**
     * Returns the sum of two `long_word` values.
     */
    inline constexpr long_word operator +(const long_word &x,
        const long_word &y) noexcept
    {
        return long_word(x.to_uint() + y.to_uint());
    }

    /**
     * Returns the difference of two `long_word` values.
     */
    inline constexpr long_word operator -(const long_word &x,
        const long_word &y) noexcept
    {
        return long_word(x.to_uint() - y.to_uint());
    }

    inline void swap(long_word &x, long_word &y) noexcept
    {
        x.swap(y);
    }
}

#endif
