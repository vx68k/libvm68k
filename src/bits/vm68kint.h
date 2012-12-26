/*
 * Integral type definitions
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

/* TODO: This header is not tested. */

#ifndef vm68kintH
#define vm68kintH 1

#if __cplusplus >= 201103L

#include <cstdint>

namespace vm68k
{
    using std::int_least8_t;
    using std::uint_least8_t;
    using std::int_least16_t;
    using std::uint_least16_t;
    using std::int_least32_t;
    using std::uint_least32_t;

    using std::int_fast8_t;
    using std::uint_fast8_t;
    using std::int_fast16_t;
    using std::uint_fast16_t;
    using std::int_fast32_t;
    using std::uint_fast32_t;
}

#else

#include <bits/vm68kint1.h>

#endif /* __cplusplus < 201103L */

#endif
