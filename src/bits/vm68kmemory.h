/*
 * Memory components.
 * Copyright (C) 2012 Kaz Nishimura
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

#ifndef vm68kmemoryH
#define vm68kmemoryH 1

#include <bits/vm68kdef.h>
#include <exception>
#include <cstdint>

namespace vm68k
{
    class _VM68K_PUBLIC memory_exception : public std::exception {
    public:
        memory_exception() noexcept;
        memory_exception(const memory_exception &x) noexcept;
        memory_exception &operator =(const memory_exception &x) noexcept;
        const char *what() const noexcept override;
    };

    class _VM68K_PUBLIC bus_error : public memory_exception {
    public:
        bus_error() noexcept;
        bus_error(const bus_error &x) noexcept;
        bus_error &operator =(const bus_error &x) noexcept;
        const char *what() const noexcept override;
    };

    class _VM68K_PUBLIC address_error : public memory_exception {
    public:
        address_error() noexcept;
        address_error(const address_error &x) noexcept;
        address_error &operator =(const address_error &x) noexcept;
        const char *what() const noexcept override;
    };

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
}

#endif
