/*
 * Integral types based on Boost libraries.
 * Copyright (C) 2012 Kaz Nishimura
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

#ifndef vm68kint_boostH
#define vm68kint_boostH 1

#include <boost/cstdint.hpp>

namespace vm68k
{
    using boost::int_least8_t;
    using boost::uint_least8_t;
    using boost::int_least16_t;
    using boost::uint_least16_t;
    using boost::int_least32_t;
    using boost::uint_least32_t;

    using boost::int_fast8_t;
    using boost::uint_fast8_t;
    using boost::int_fast16_t;
    using boost::uint_fast16_t;
    using boost::int_fast32_t;
    using boost::uint_fast32_t;
}

#endif
