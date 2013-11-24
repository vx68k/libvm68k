/*
 * Target data (interface)
 * Copyright (C) 2012-2013 Kaz Nishimura
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef vm68kdataH
#define vm68kdataH 1

#include <bits/vm68kdef.h>
#include <type_traits>
#include <limits>
#include <cstdint>

namespace vm68k
{
    using std::size_t;

    /**
     * Provides members for the target data sizes.
     */
    template<typename IntT, typename IntFastT>
    struct _VM68K_EXPORT data_size {
        static_assert(std::is_signed<IntT>::value, "IntT must be signed");
        static_assert(std::is_signed<IntFastT>::value, "IntT must be signed");
        static_assert(sizeof (IntFastT) >= sizeof (IntT),
                "IntFastT must be less shorter than IntT");

        typedef IntT int_type;
        typedef typename std::make_unsigned<IntT>::type uint_type;

        typedef IntFastT int_fast_type;
        typedef typename std::make_unsigned<IntFastT>::type uint_fast_type;

        /**
         * Returns the size in bytes.
         * @return the size.
         */
        static constexpr size_t size() noexcept {
            return sizeof (int_type);
        }

        /**
         * Returns the size in bytes when aligned to a word boundary.
         * @return the word-aligned size.
         */
        static constexpr size_t word_aligned_size() noexcept {
            return (size() + 1U) & ~1U;
        }

        /**
         * Returns the minimum signed integral value
         * @return the minimum value.
         */
        static constexpr int_type int_min() noexcept {
            return std::numeric_limits<int_type>::min();
        }

        /**
         * Returns the maximum signed integral value
         * @return the maximum value.
         */
        static constexpr int_type int_max() noexcept {
            return std::numeric_limits<int_type>::max();
        }

        /**
         * Returns the maximum unsigned integral value
         * @return the maximum value.
         */
        static constexpr uint_type uint_max() noexcept {
            return std::numeric_limits<uint_type>::max();
        }
    };

    typedef data_size<std::int8_t,  std::int_fast8_t>  byte;
    typedef data_size<std::int16_t, std::int_fast16_t> word;
    typedef data_size<std::int32_t, std::int_fast32_t> lword;
    // No implicit instantiation.
    extern template class data_size<std::int8_t,  std::int_fast8_t>;
    extern template class data_size<std::int16_t, std::int_fast16_t>;
    extern template class data_size<std::int32_t, std::int_fast32_t>;

    /**
     * Data of a specific size.
     */
    template<typename Size>
    class _VM68K_EXPORT basic_data {
        typedef basic_data<Size> inherited;

    public:
        /**
         * Constructs this object with an initial value.
         * @param x optional initial value; if omitted, initialized to 0.
         */
        constexpr basic_data(typename Size::uint_type x = 0) noexcept :
        value(x) {
        }

        /**
         * Returns the value of this object as the signed integral type.
         * @return the signed integral value.
         */
        constexpr typename Size::int_type to_int() const noexcept {
            return value;
        }

        /**
         * Returns the value of this object as the unsigned integral type.
         * @return the unsigned integral value.
         */
        constexpr typename Size::uint_type to_uint() const noexcept {
            return value;
        }

        // TODO: Add more members.

    private:
        typename Size::uint_type value;
    };

    typedef basic_data<byte>  byte_data;
    typedef basic_data<word>  word_data;
    typedef basic_data<lword> lword_data;
    // No implicit instantiation.
    extern template class basic_data<byte>;
    extern template class basic_data<word>;
    extern template class basic_data<lword>;
}

#endif
