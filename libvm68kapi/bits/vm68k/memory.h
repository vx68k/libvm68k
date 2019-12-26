// <bits/vm68k/memory.h>
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

#ifndef _VM68K_MEMORY_H
#define _VM68K_MEMORY_H 1

#include <bits/vm68kapi.h>
#include <exception>
#include <cstdint>

namespace vm68k
{
    /**
     * <author>Kaz Nishimura</author>
     * <since>2.0</since>
     */
    class _VM68KAPI_PUBLIC memory
    {
    public:
        enum mode
        {
            USER_MODE = 0,
            SUPERVISOR_MODE,
        };

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
        virtual ~memory();

    public:
        // Returns the size of this memory object.
        virtual std::size_t size() const = 0;

        // Reads a sequence of bytes.
        virtual void read(std::uint_fast32_t address, std::size_t size,
            mode m, void *data) = 0;

        // Writes a sequence of bytes.
        virtual void write(std::uint_fast32_t address, std::size_t size,
            mode m, const void *data) = 0;
    };

    /**
     * <author>Kaz Nishimura</author>
     * <since>2.0</since>
     */
    class _VM68KAPI_PUBLIC memory_map
    {
    public:
        using mode = memory::mode;

    public:
        typedef std::uint32_t address_type;

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
        virtual void read(std::uint_fast32_t address, std::size_t size,
            mode m, void *data) = 0;

        // Writes a sequence of bytes.
        virtual void write(std::uint_fast32_t address, std::size_t size,
            mode m, const void *data) = 0;
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
