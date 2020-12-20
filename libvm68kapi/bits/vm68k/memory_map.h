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
     * Base class for memory maps.
     *
     * <author>Kaz Nishimura</author>
     * <since>2.0</since>
     */
    class _VM68KAPI_PUBLIC memory_map
    {
    public:
        using address_type = std::uint32_t;
        using size_type = std::uint32_t;

    public:
        /**
         * Access mode.
         */
        enum class access_mode: char
        {
            USER = 0,
            SUPERVISOR,
        };

    public:
        /**
         * Memory objects mapped on a memory map.
         */
        class _VM68KAPI_PUBLIC memory
        {
        protected:
            using address_type = memory_map::address_type;
            using size_type = memory_map::size_type;
            using access_mode = memory_map::access_mode;

        protected:
            memory() = default;

            memory(const memory &other) = default;

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
            virtual void read(access_mode mode, address_type address,
                size_type size, void *bytes) = 0;

            /**
             * Writes a sequence of bytes to the memory object.
             */
            virtual void write(access_mode mode, address_type address,
                size_type size, const void *bytes) = 0;
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
        /**
         * Reads a sequence of bytes.
         *
         * @param mode an access mode
         * @param address the first address of the sequence
         * @param size the size of the sequence
         * @param bytes a pointer to a byte buffer
         */
        virtual void read(access_mode mode, address_type address,
            size_type size, void *bytes) = 0;

    public:
        /**
         * Writes a sequence of bytes.
         *
         * @param mode an access mode
         * @param address the first address of the sequence
         * @param size the size of the sequence
         * @param bytes a pointer to a byte buffer
         */
        virtual void write(access_mode mode, address_type address,
            size_type size, const void *bytes) = 0;
    };

    /**
     * Paged memory maps.
     */
    class _VM68KAPI_PUBLIC paged_memory_map: public memory_map
    {
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

        paged_memory_map(const paged_memory_map &other) = delete;

        paged_memory_map(paged_memory_map &&other) noexcept;

    public:
        virtual ~paged_memory_map();

    public:
        void operator =(const paged_memory_map &other) = delete;

        paged_memory_map &operator =(paged_memory_map &&other) noexcept
        {
            swap(other);
            return *this;
        }

    public:
        /**
         * Swaps the contents with another.
         *
         * @param other another paged memory map
         */
        void swap(paged_memory_map &other) noexcept;

    public:
        /**
         * Returns the address mask.
         */
        address_type address_mask() const noexcept
        {
            return _address_mask;
        }

    public:
        /**
         * Returns the page size.
         */
        size_type page_size() const noexcept
        {
            return _page_size;
        }

    public:
        /**
         * Adds a memory to the memory map.
         */
        void add_memory(address_type address,
            const std::shared_ptr<memory> &memory);

    public:
        virtual void read(access_mode mode, address_type address,
            size_type size, void *bytes) override;

    public:
        virtual void write(access_mode mode, address_type address,
            size_type size, const void *bytes) override;
    };

    /**
     * Swaps the contents of two paged memory maps.
     *
     * @param one a paged memory map
     * @param other another paged memory map
     */
    inline void swap(paged_memory_map &one, paged_memory_map &other) noexcept
    {
        one.swap(other);
    }
}

#endif
