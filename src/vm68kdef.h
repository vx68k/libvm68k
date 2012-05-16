/*
 * Base definitions.
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

#ifndef vm68kdefH
#define vm68kdefH

#include <vm68kint.h>
#include <cstddef>

#ifndef VM68K_EXPORT
#if _WIN32
#define VM68K_EXPORT __declspec(dllimport)
#else
#define VM68K_EXPORT
#endif
#endif /* !defined VM68K_EXPORT */

namespace vm68k
{
    template<std::size_t Size>
    struct size_traits;

    template<>
    struct size_traits<1U>
    {
        typedef int_least8_t int_type;
        typedef uint_least8_t uint_type;
        typedef int_fast8_t int_fast_type;
        typedef uint_fast8_t uint_fast_type;
    };

    template<>
    struct size_traits<2U>
    {
        typedef int_least16_t int_type;
        typedef uint_least16_t uint_type;
        typedef int_fast16_t int_fast_type;
        typedef uint_fast16_t uint_fast_type;
    };

    template<>
    struct size_traits<4U>
    {
        typedef int_least32_t int_type;
        typedef uint_least32_t uint_type;
        typedef int_fast32_t int_fast_type;
        typedef uint_fast32_t uint_fast_type;
    };

    template<std::size_t Size, class Traits = size_traits<Size> >
    class data
    {
    public:
        typedef Traits traits_type;

        typedef typename Traits::int_type int_type;
        typedef typename Traits::uint_type uint_type;
        typedef typename Traits::int_fast_type int_fast_type;
        typedef typename Traits::uint_fast_type uint_fast_type;

    private:
        int_type value;

    public:
        static std::size_t size()
        {
            return Size;
        }

        static int_fast_type int_min()
        {
            return int_fast_type(-1) << (size() * 8 - 1);
        }

        static int_fast_type int_max()
        {
            return (int_fast_type(1) << (size() * 8 - 1)) - 1;
        }

        static uint_fast_type uint_max()
        {
            return (uint_fast_type(1) << (size() * 8)) - 1;
        }

        static int_fast_type to_int_type(uint_fast_type x)
        {
            x &= uint_max();
            if (x > int_max())
                x -= uint_fast_type(1) << (size() * 8);
            return int_fast_type(x);
        }

        /**
         * <stereotype>constructor</stereotype>
         */
        data()
        {
        }

        /**
         * <stereotype>constructor</stereotype>
         */
        data(uint_fast_type x)
        {
            value = to_int_type(x);
        }

        operator int_fast_type() const
        {
            return value;
        }
    };

    typedef data<1U> byte;
    typedef data<2U> word;
    typedef data<4U> long_word;
}

#endif
