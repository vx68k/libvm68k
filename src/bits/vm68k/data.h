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
    /**
     * Defines data size properties.
     */
    template<unsigned int Size>
    struct size_traits;

    template<>
    struct _VM68KCORE_PUBLIC size_traits<1> {
        typedef std::int8_t      int_type;
        typedef std::int_fast8_t int_fast_type;

        typedef std::uint8_t      uint_type;
        typedef std::uint_fast8_t uint_fast_type;
    };

    template<>
    struct _VM68KCORE_PUBLIC size_traits<2> {
        typedef std::int16_t      int_type;
        typedef std::int_fast16_t int_fast_type;

        typedef std::uint16_t      uint_type;
        typedef std::uint_fast16_t uint_fast_type;
    };

    template<>
    struct _VM68KCORE_PUBLIC size_traits<4> {
        typedef std::int32_t      int_type;
        typedef std::int_fast32_t int_fast_type;

        typedef std::uint32_t      uint_type;
        typedef std::uint_fast32_t uint_fast_type;
    };

    /**
     * Data of a specific size.
     */
    template<unsigned int Size, typename Traits = size_traits<Size>>
    class _VM68KCORE_PUBLIC basic_data {
    public:
        typedef Traits traits_type;

        typedef typename Traits::int_type      int_type;
        typedef typename Traits::int_fast_type int_fast_type;

        typedef typename Traits::uint_type      uint_type;
        typedef typename Traits::uint_fast_type uint_fast_type;

        /**
         * Returns the size of this data type.
         * @return size.
         */
        static constexpr unsigned int size() noexcept {
            return Size;
        }

        /**
         * Constructs this object with an initial value.
         * @param x optional initial value; if omitted, initialized to 0.
         */
        constexpr basic_data(uint_type x = 0) noexcept :
        value(x) {
        }

        /**
         * Returns the value of this object as the signed integral type.
         * @return the signed integral value.
         */
        constexpr int_type to_int() const noexcept {
            return value;
        }

        /**
         * Returns the value of this object as the unsigned integral type.
         * @return the unsigned integral value.
         */
        constexpr uint_type to_uint() const noexcept {
            return value;
        }

        // TODO: Add more members.

    private:
        uint_type value;
    };

    typedef basic_data<1> byte_data;
    typedef basic_data<2> word_data;
    typedef basic_data<4> long_word_data;
    // No implicit instantiation.
    extern template class basic_data<1>;
    extern template class basic_data<2>;
    extern template class basic_data<4>;
}

#endif
