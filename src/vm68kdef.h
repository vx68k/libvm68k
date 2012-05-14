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

#ifndef VM68K_EXPORT
#if _WIN32
#define VM68K_EXPORT __declspec(dllimport)
#else
#define VM68K_EXPORT
#endif
#endif /* !defined VM68K_EXPORT */

namespace vm68k
{
    class VM68K_EXPORT byte
    {
    public:
        typedef int_least8_t int_type;
        typedef uint_least8_t uint_type;

        /**
         * <stereotype>constructor</stereotype>
         */
        byte();

        /**
         * <stereotype>constructor</stereotype>
         */
        byte(uint_fast8_t x);

        operator int_fast8_t() const ;

    private:
        uint_least8_t value;
    };

    class VM68K_EXPORT word
    {
    public:
        typedef int_least16_t int_type;
        typedef uint_least16_t uint_type;

        /**
         * <stereotype>constructor</stereotype>
         */
        word();

        /**
         * <stereotype>constructor</stereotype>
         */
        word(uint_fast16_t x);

        operator int_fast16_t() const;

    private:
        uint_least16_t value;
    };

    class VM68K_EXPORT long_word
    {
    public:
        typedef int_least32_t int_type;
        typedef uint_least32_t uint_type;

        /**
         * <stereotype>constructor</stereotype>
         */
        long_word();

        /**
         * <stereotype>constructor</stereotype>
         */
        long_word(uint_fast32_t x);

        operator int_fast32_t() const;

    private:
        uint_least32_t value;
    };

    typedef long_word lword;

    /* Inline implementations.  */

    inline byte::byte()
    {
    }

    inline byte::byte(uint_fast8_t x)
    {
        value = x & 0xff;
    }

    inline byte::operator int_fast8_t() const
    {
        return value;
    }

    inline word::word()
    {
    }

    inline word::word(uint_fast16_t x)
    {
        value = x & 0xffff;
    }

    inline word::operator int_fast16_t() const
    {
        return value;
    }

    inline long_word::long_word()
    {
    }

    inline long_word::long_word(uint_fast32_t x)
    {
        value = x;
    }

    inline long_word::operator int_fast32_t() const
    {
        return value;
    }
}

#endif
