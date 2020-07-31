// <bits/vm68k/memory_map.h>
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

#ifndef _VM68K_MEMORY_MAP_H
#define _VM68K_MEMORY_MAP_H 1

#include <bits/vm68kapi.h>
#include <exception>
#include <cstdint>

namespace vm68k
{
    /**
     * <author>Kaz Nishimura</author>
     * <since>2.0</since>
     */
    class _VM68KAPI_PUBLIC memory_map
    {
    public:
        enum mode
        {
            USER = 0,
            SUPERVISOR,
        };

        using address_type = std::uint_fast32_t;
        using size_type = std::size_t;

    protected:
        /**
         * <stereotype>constructor</stereotype>
         */
        memory_map() = default;

    public:
        /**
         * <stereotype>destructor</stereotype>
         */
        virtual ~memory_map() = default;

    public:
        // Reads a sequence of bytes.
        virtual void read(mode m, address_type address, size_type n,
            void *bytes) = 0;

        // Writes a sequence of bytes.
        virtual void write(mode m, address_type address, size_type n,
            const void *bytes) = 0;
    };

    /**
     * Paged memory maps.
     */
    class _VM68KAPI_PUBLIC paged_memory_map: public memory_map
    {
    public:
        static const size_type PAGE_SIZE_MIN = 0x1000U;

    private:
        address_type _address_mask;

    private:
        size_type _page_size;

    public:
        paged_memory_map();

        explicit paged_memory_map(address_type address_mask);

        paged_memory_map(address_type address_mask, size_type page_size);

    public:
        virtual ~paged_memory_map();

    public:
        address_type address_mask() const noexcept
        {
            return _address_mask;
        }

    public:
        size_type page_size() const noexcept
        {
            return _page_size;
        }
    };

    class _VM68KAPI_PUBLIC memory_exception : public std::exception {
        typedef std::exception inherited;

    public:
        explicit memory_exception(memory_map::address_type address) noexcept;

        memory_map::address_type error_address() const noexcept {
            return _error_address;
        }

        const char *what() const noexcept override;
    private:
        memory_map::address_type _error_address;
    };

    class _VM68KAPI_PUBLIC bus_error : public memory_exception {
        typedef memory_exception inherited;

    public:
        explicit bus_error(memory_map::address_type address) noexcept;
        bus_error(const bus_error &x) noexcept;
        bus_error &operator =(const bus_error &x) noexcept;
        const char *what() const noexcept override;
    };

    class _VM68KAPI_PUBLIC address_error : public memory_exception {
        typedef memory_exception inherited;

    public:
        address_error(memory_map::address_type address) noexcept;
        address_error(const address_error &x) noexcept;
        address_error &operator =(const address_error &x) noexcept;
        const char *what() const noexcept override;
    };
}

#endif
