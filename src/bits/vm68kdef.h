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
#define vm68kdefH 1

#ifndef _VM68K_EXPORT
#define _VM68K_EXPORT
#endif

#ifndef _VM68K_CONSTEXPR
#if __cplusplus >= 201103L
#define _VM68K_CONSTEXPR constexpr
#else
#define _VM68K_CONSTEXPR /*nothing*/
#endif
#endif

#ifndef _VM68K_NOEXCEPT
#if __cplusplus >= 201103L
#define _VM68K_NOEXCEPT noexcept
#else
#define _VM68K_NOEXCEPT throw()
#endif
#endif

#endif
