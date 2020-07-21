// <bits/vm68kcore.h>
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

#ifndef _VM68KCORE_H
#define _VM68KCORE_H 1

#ifndef _VM68KCORE_PUBLIC
#if _WIN32
#if _LIBVM68K
#if DLL_EXPORT
#define _VM68KCORE_PUBLIC __declspec(dllexport)
#endif
#else /* not _LIBVM68K */
#define _VM68KCORE_PUBLIC __declspec(dllimport)
#endif /* not _LIBVM68K */
#else /* not _WIN32 */
#if defined __has_attribute
#if __has_attribute(visibility)
#define _VM68KCORE_PUBLIC __attribute__((visibility("default")))
#endif
#endif /* defined __has_attribute */
#endif /* not _WIN32 */
#endif

#ifndef _VM68KCORE_PUBLIC
#define _VM68KCORE_PUBLIC
#endif

#endif
