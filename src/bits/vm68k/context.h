// <bits/vm68k/context.h>
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

#ifndef _VM68K_CONTEXT_H
#define _VM68K_CONTEXT_H 1

#include <bits/vm68k/register.h>
#include <bits/vm68kcore.h>
#include <vm68k/memory>
#include <memory>
#include <utility>

namespace vm68k
{
    /*
     * Execution context.
     */
    class _VM68KCORE_PUBLIC context
    {
    private:
        std::shared_ptr<memory_map> _memory;

    public:
        explicit context(const std::shared_ptr<memory_map> &memory);

    public:
        virtual ~context();

    public:
        const std::shared_ptr<memory_map> &memory() const noexcept
        {
            return _memory;
        }
    };
}

#endif
