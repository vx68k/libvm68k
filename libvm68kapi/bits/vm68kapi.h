// <bits/vm68kapi.h>
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

#ifndef _VM68K_APIDEF_H
#define _VM68K_APIDEF_H 1

#ifndef _VM68KAPI_PUBLIC
#if _WIN32
#if VM68KAPI_DLL
#define _VM68KAPI_PUBLIC __declspec(dllexport)
#else
#define _VM68KAPI_PUBLIC __declspec(dllimport)
#endif
#else /* !_WIN32 */
#if defined __has_attribute
#if __has_attribute(visibility)
#define _VM68KAPI_PUBLIC __attribute__((visibility("default")))
#endif
#endif  /* defined __has_attribute */
#endif /* !_WIN32 */
#endif

#if !defined _VM68KAPI_PUBLIC
#define _VM68KAPI_PUBLIC
#endif

#ifndef _VM68K_PUBLIC
#if _WIN32
#if VM68K_DLL
#define _VM68K_PUBLIC __declspec(dllimport)
#else
#define _VM68K_PUBLIC __declspec(dllexport)
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
