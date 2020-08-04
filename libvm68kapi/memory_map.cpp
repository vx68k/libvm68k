// memory_map.cpp
// Copyright (C) 2012-2020 Kaz Nishimura
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

#if HAVE_CONFIG_H
#include <config.h>
#endif
#if __BORLANDC__
#pragma hdrstop
#endif

#define _VM68K_MEMORY_IMPLEMENTATION 1
#include <bits/vm68k/memory_map.h>

#include <stdexcept>

#if __BORLANDC__
#pragma package(smart_init)
#endif

using std::invalid_argument;
using namespace vm68k;


// Implementation of the paged memory maps.

paged_memory_map::paged_memory_map()
:
    paged_memory_map(0xffffffffUL)
{
    // Nothing to do.
}

paged_memory_map::paged_memory_map(const address_type address_mask)
:
    paged_memory_map(address_mask, DEFAULT_PAGE_SIZE)
{
    // Nothing to do.
}

paged_memory_map::paged_memory_map(const address_type address_mask,
    const size_type page_size)
:
    _address_mask {address_mask},
    _page_size {page_size}
{
    if (((_address_mask + 1) & _address_mask) != 0) {
        throw invalid_argument("invalid address mask");
    }
    if ((_page_size & (_page_size - 1)) != 0) {
        throw invalid_argument("invalid page size");
    }

    _pages.resize(_address_mask / _page_size + 1);
}

paged_memory_map::~paged_memory_map()
{
    // Nothing to do.
}

void paged_memory_map::memory::relocate(address_type)
{
    // Nothing to do.
}
