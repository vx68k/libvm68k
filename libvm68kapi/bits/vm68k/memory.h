/*
 * Memory components.
 * Copyright (C) 2012-2019 Kaz Nishimura
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _VM68K_MEMORY_H
#define _VM68K_MEMORY_H 1

#include <bits/vm68k/apidef.h>
#include <exception>
#include <cstdint>

namespace vm68k
{
    /**
     * <author>Kaz Nishimura</author>
     * <since>2.0</since>
     */
    class _VM68K_PUBLIC device
    {
    protected:
        /**
         * <stereotype>constructor</stereotype>
         */
        device()
        {
        }

    public:
        /**
         * <stereotype>destructor</stereotype>
         */
        virtual ~device();
    };

    /**
     * <author>Kaz Nishimura</author>
     * <since>2.0</since>
     */
    class _VM68K_PUBLIC memory_map
    {
    public:
        typedef std::uint32_t address_type;

        /**
         * <stereotype>constructor</stereotype>
         */
        memory_map()
        {
        }

        /**
         * <stereotype>destructor</stereotype>
         */
        virtual ~memory_map();
    };

    class _VM68K_PUBLIC memory_exception : public std::exception {
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

    class _VM68K_PUBLIC bus_error : public memory_exception {
        typedef memory_exception inherited;

    public:
        explicit bus_error(memory_map::address_type address) noexcept;
        bus_error(const bus_error &x) noexcept;
        bus_error &operator =(const bus_error &x) noexcept;
        const char *what() const noexcept override;
    };

    class _VM68K_PUBLIC address_error : public memory_exception {
        typedef memory_exception inherited;

    public:
        address_error(memory_map::address_type address) noexcept;
        address_error(const address_error &x) noexcept;
        address_error &operator =(const address_error &x) noexcept;
        const char *what() const noexcept override;
    };
}

#endif
