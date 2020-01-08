// <bits/vm68k/module.h>
// Copyright (C) 2020 Kaz Nishimura
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

#ifndef _VM68K_MODULE_H
#define _VM68K_MODULE_H 1

#include <bits/vm68kapi.h>
#include <cstdint>

namespace vm68k
{
    namespace module
    {
        class _VM68KAPI_PUBLIC module_loader
        {
        };

        struct _VM68KAPI_PUBLIC module
        {
            std::uint_least16_t major;
            std::uint_least16_t minor;
        };
    }
}

#endif
