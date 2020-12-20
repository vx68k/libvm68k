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
#include <algorithm>
#include <utility>
#include <stdexcept>

using std::fill;
using std::invalid_argument;
using std::make_shared;
using std::shared_ptr;
using std::swap;
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

paged_memory_map::paged_memory_map(paged_memory_map &&other) noexcept
{
    swap(other);
}

paged_memory_map::~paged_memory_map()
{
    // Nothing to do.
}

paged_memory_map &paged_memory_map::operator =(paged_memory_map &&other) noexcept
{
    swap(other);
    return *this;
}

void paged_memory_map::add_memory(address_type address,
    const shared_ptr<memory> &memory)
{
    if ((address & (_page_size - 1U)) != 0U) {
        throw invalid_argument("address not aligned to page boundaries");
    }
    if ((address & ~_address_mask) != 0U) {
        return;
    }

    auto first = _pages.begin() + address / _page_size;
    auto last = first + (memory->size() + _page_size - 1U) / _page_size;
    if (last > _pages.end()) {
        last = _pages.end();
    }
    fill(first, last, memory);
}

void paged_memory_map::read(const access_mode mode, address_type address,
    size_type size, void *bytes)
{
    auto page = _pages.begin() + (address & _address_mask) / _page_size;
    while (size != 0) {
        auto transfer_size = size;
        auto offset = address & (_page_size - 1U);
        if (transfer_size > _page_size - offset) {
            transfer_size = _page_size - offset;
        }

        (*page++)->read(mode, address, transfer_size, bytes);
        if (page == _pages.end()) {
            page = _pages.begin();
        }
        address += transfer_size;
        size -= transfer_size;
        bytes = static_cast<char *>(bytes) + transfer_size;
    }
}

void paged_memory_map::write(const access_mode mode, address_type address,
    size_type size, const void *bytes)
{
    auto page = _pages.begin() + (address & _address_mask) / _page_size;
    while (size != 0) {
        auto transfer_size = size;
        auto offset = address & (_page_size - 1U);
        if (transfer_size > _page_size - offset) {
            transfer_size = _page_size - offset;
        }

        (*page++)->write(mode, address, transfer_size, bytes);
        if (page == _pages.end()) {
            page = _pages.begin();
        }
        address += transfer_size;
        size -= transfer_size;
        bytes = static_cast<const char *>(bytes) + transfer_size;
    }
}
