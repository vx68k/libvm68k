/*
 * Integral types for older systems.
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

#ifndef vm68kint_classicH
#define vm68kint_classicH 1

#if __cplusplus >= 201103L

#include <vm68kint_std11.h>

#else

namespace vm68k
{
    typedef signed char    int_least8_t;
    typedef unsigned char  uint_least8_t;
    typedef short          int_least16_t;
    typedef unsigned short uint_least16_t;
    typedef int            int_least32_t;
    typedef unsigned int   uint_least32_t;

    typedef int            int_fast8_t;
    typedef unsigned int   uint_fast8_t;
    typedef int            int_fast16_t;
    typedef unsigned int   uint_fast16_t;
    typedef int            int_fast32_t;
    typedef unsigned int   uint_fast32_t;
}

#endif /* __cplusplus < 201103L */

#endif /* once */
