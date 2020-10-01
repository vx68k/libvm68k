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

#include <bits/vm68kapidef.h>
#include <vector>
#include <memory>
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
        using address_type = std::uint32_t;
        using size_type = std::uint32_t;

        enum class mode: char
        {
            USER = 0,
            SUPERVISOR,
        };

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
        /**
         * Memory objects mapped to the paged memory map.
         */
        class _VM68KAPI_PUBLIC memory
        {
        protected:
            using address_type = memory_map::address_type;
            using size_type = memory_map::size_type;

        protected:
            memory() = default;

            memory(const memory &) = delete;

        public:
            void operator =(const memory &) = delete;

        public:
            virtual ~memory() = default;

        public:
            /**
             * Returns the size of the memory object.
             */
            virtual size_type size() const noexcept = 0;

            /**
             * Changes the base address of the memory object.
             *
             * This implementation does nothing.
             */
            virtual void relocate(address_type base);

            /**
             * Reads a sequence of bytes from the memory object.
             */
            virtual void read(mode mode, address_type address, size_type n,
                void *bytes) = 0;

            /**
             * Writes a sequence of bytes to the memory object.
             */
            virtual void write(mode mode, address_type address, size_type n,
                const void *bytes) = 0;
        };

    public:
        static const size_type DEFAULT_PAGE_SIZE = 0x1000U;

    private:
        address_type _address_mask;

    private:
        size_type _page_size;

    private:
        std::vector<std::shared_ptr<memory>> _pages;

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
}

#endif
