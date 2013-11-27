/*
 * Base definitions
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

#ifndef vm68kdefH
#define vm68kdefH 1

#ifndef _VM68K_PUBLIC
#if _WIN32 && !VM68K_STATIC
#if VM68K_DLL
#define _VM68K_PUBLIC __declspec(dllexport)
#else
#define _VM68K_PUBLIC __declspec(dllimport)
#endif
#else /* _WIN32 && !_VM68K_STATIC */
#if __GNUC__ >= 4
#define _VM68K_PUBLIC __attribute__((visibility("default")))
#else
#define _VM68K_PUBLIC
#endif
#endif /* _WIN32 && !_VM68K_STATIC */
#endif

#endif
