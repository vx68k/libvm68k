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
#include <memory>
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

    public:
        /**
         * <stereotype>constructor</stereotype>
         */
        memory_map();

    public:
        /**
         * <stereotype>destructor</stereotype>
         */
        virtual ~memory_map();

    public:
        // Reads a sequence of bytes.
        virtual void read(mode m, address_type address, size_type n,
            void *bytes) = 0;

        // Writes a sequence of bytes.
        virtual void write(mode m, address_type address, size_type n,
            const void *bytes) = 0;
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

    /**
     * <author>Kaz Nishimura</author>
     * <since>2.0</since>
     */
    class _VM68KAPI_PUBLIC memory
    {
    public:
        using mode = memory_map::mode;
        using address_type = memory_map::address_type;
        using size_type = memory_map::size_type;

    protected:
        /**
         * <stereotype>constructor</stereotype>
         */
        memory();

        memory(const memory &) = delete;
        memory &operator =(const memory &) = delete;

    public:
        /**
         * <stereotype>destructor</stereotype>
         */
        virtual ~memory() = 0;

    public:
        // Changes the base address of this memory.
        //
        // This implementation does nothing.
        virtual void relocate(address_type base);

        // Returns the size of this memory object.
        virtual size_type size() const noexcept = 0;

        // Reads a sequence of bytes.
        virtual void read(mode m, address_type address, size_type n,
            void *bytes) = 0;

        // Writes a sequence of bytes.
        virtual void write(mode m, address_type address, size_type n,
            const void *bytes) = 0;
    };

    /// Read-write memory.
    class _VM68KAPI_PUBLIC read_write_memory : public memory
    {
        using inherited = memory;

    protected:
        using byte_type = unsigned char;

    protected:
        static std::unique_ptr<byte_type []> allocate(size_type size);

    private:
        const size_type _size;
        std::unique_ptr<byte_type []> _data;

    public:
        explicit read_write_memory(size_type size);

    public:
        virtual ~read_write_memory();

    public:
        size_type size() const noexcept override final;

        void read(mode m, address_type address, size_type n,
            void *bytes) override final;

        void write(mode m, address_type address, size_type n,
            const void *bytes) override final;

    protected:
        /// Checks read access on a region.
        ///
        /// This implementation does nothing.
        virtual void check_read_access(mode m, address_type address,
            size_type n);

        /// Checks write access on a region.
        ///
        /// This implementation does nothing.
        virtual void check_write_access(mode m, address_type address,
            size_type n);
    };
}

#endif
