/*
 * vm68kdata - target data type definitions (interface)
 * Copyright (C) 2012  Kaz Sasa
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef vm68kdataH
#define vm68kdataH 1

#include <bits/vm68kint.h>

namespace vm68k
{
    /*
     * Base class for data types.
     */
    template<unsigned int N, typename IntT, typename UIntT>
    class basic_data {
        /*
         * Tests if a basic_data object equals to another.
         */
        friend bool operator ==(const basic_data &x, const basic_data &y) {
            return x.value == y.value;
        }

        /*
         * Tests if a basic_data object does not equal to another.
         */
        friend bool operator !=(const basic_data &x, const basic_data &y) {
            return x.value != y.value;
        }

    public:
        typedef uint_least32_t size_type;
        typedef IntT int_type;
        typedef UIntT unsigned_int_type;

        /*
         * Returns the size of this class in bytes.
         */
        static constexpr size_type size() {
            return (N + 7U) >> 3;
        }

        /*
         * Returns the minimum value for signed integers.
         */
        static constexpr int_type min() {
            return ~(int_type)0 << N - 1;
        }

        /*
         * Returns the maximum value for signed integers.
         */
        static constexpr int_type max() {
            return ~min();
        }

        /*
         * Returns the maximum value for unsigned integers.
         */
        static constexpr unsigned_int_type umax() {
            return ~(~(unsigned_int_type)1 << N - 1);
        }

        int_type get() const {
            return value;
        }

        unsigned_int_type uget() const {
            return (unsigned_int_type)get() & umax();
        }

        operator int_type() const {
            return get();
        }

    protected:
        static int_type to_int(unsigned_int_type x) {
            x &= umax();
            if (x >= (unsigned_int_type) 1 << N - 1) {
                return -1 - (int_type)(umax() - x);
            }
            return (int_type)x;
        }

        basic_data(unsigned_int_type x) : value(to_int(x)) {
        }

        basic_data(const basic_data &x) : value(x.value) {
        }

    private:
        int_type value;
    };

    /*
     * Target byte type.  This type is 8-bit long.
     */
    class byte : public basic_data<8, int_least8_t, uint_least8_t> {
    public:
        byte(unsigned_int_type x = 0) : base(x) {
        }

    private:
        typedef basic_data<8, int_least8_t, uint_least8_t> base;
    };

    /*
     * Target word type.  This type is 16-bit long.
     */
    class word : public basic_data<16, int_least16_t, uint_least16_t> {
    public:
        word(unsigned_int_type x = 0) : base(x) {
        }

    private:
        typedef basic_data<16, int_least16_t, uint_least16_t> base;
    };

    /*
     * Target long word type.  This type is 32-bit long.
     */
    class long_word : public basic_data<32, int_least32_t, uint_least32_t> {
    public:
        long_word(unsigned_int_type x = 0) : base(x) {
        }

    private:
        typedef basic_data<32, int_least32_t, uint_least32_t> base;
    };
}

#endif