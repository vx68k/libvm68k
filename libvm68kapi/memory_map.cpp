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

#include <bits/vm68k/memory_map.h>

#include <bits/vm68k/memory_exception.h>
#include <stdexcept>

using std::invalid_argument;
using std::make_shared;
using std::shared_ptr;
using namespace vm68k;

namespace
{
    /**
     * Memories that causes a bus error on every access.
     */
    class bus_error_memory: public memory_map::memory
    {
    public:
        size_type size() const noexcept final override
        {
            return 0U;
        }

    public:
        void read(access_mode mode, address_type address, size_type,
            void *) final override
        {
            throw bus_error(mode, address);
        }

    public:
        void write(access_mode mode, address_type address, size_type,
            const void *) final override
        {
            throw bus_error(mode, address);
        }
    };
}

static const auto NO_MEMORY = make_shared<bus_error_memory>();


void memory_map::memory::relocate(address_type)
{
    // Nothing to do.
}

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
    if (((_address_mask + 1U) & _address_mask) != 0U) {
        throw invalid_argument("invalid address mask");
    }
    if ((_page_size & (_page_size - 1U)) != 0U) {
        throw invalid_argument("invalid page size");
    }

    _pages.resize(_address_mask / _page_size + 1U, NO_MEMORY);
}

paged_memory_map::~paged_memory_map()
{
    // Nothing to do.
}

void paged_memory_map::add_memory(address_type address,
    const shared_ptr<memory> &memory)
{
    if ((address & (_page_size - 1U)) != 0U) {
        throw invalid_argument("address not aligned to page boundaries");
    }
    address &= _address_mask;

    auto last = (address + memory->size()) & _address_mask;
    auto page_index = address / _page_size;
    auto last_page_index = last / _page_size;
    while (page_index != last_page_index) {
        _pages[page_index++] = memory;
    }
}

void paged_memory_map::read(const access_mode mode, address_type address,
    size_type size, void *bytes)
{
    address &= _address_mask;

    auto last = (address + size) & _address_mask;
    while (address != last) {
        auto page_index = address / _page_size;
        auto &page = _pages[page_index];
        // TODO: implement this function.
    }
}

void paged_memory_map::write(const access_mode mode, address_type address,
    size_type size, const void *bytes)
{
    address &= _address_mask;

    auto last = (address + size) & _address_mask;
    while (address != last) {
        auto page_index = address / _page_size;
        auto &page = _pages[page_index];
        // TODO: implement this function.
    }
}
