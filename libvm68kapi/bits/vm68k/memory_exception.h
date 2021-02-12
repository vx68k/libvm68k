// <bits/vm68k/memory_exception.h>
// Copyright (C) 2012-2021 Kaz Nishimura
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

#ifndef _VM68K_MEMORY_EXCEPTION_H
#define _VM68K_MEMORY_EXCEPTION_H 1

#include <bits/vm68k/memory_map.h>
#include <exception>

namespace vm68k
{
#if _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4275)
#endif

    /**
     * Generic memory exceptions.
     */
    class _VM68KAPI_PUBLIC memory_exception: public std::exception
    {
    private:

        function_code _fc;

        memory_map::address_type _address;

    public:

        // Constructors.

        memory_exception(function_code fc, memory_map::address_type address)
            noexcept;

        memory_exception(const memory_exception &other) noexcept;


        // Destructor.

        virtual ~memory_exception();


        // Assignment operators.

        memory_exception &operator =(const memory_exception &other) noexcept;


        function_code fc() const noexcept
        {
            return _fc;
        }

        memory_map::address_type address() const noexcept
        {
            return _address;
        }

        const char *what() const noexcept override;
    };

#if _MSC_VER
#pragma warning(pop)
#endif

    /**
     * Bus errors.
     */
    class _VM68KAPI_PUBLIC bus_error: public memory_exception
    {
    public:

        // Constructors.

        bus_error(function_code fc, memory_map::address_type address)
            noexcept;


        const char *what() const noexcept override;
    };

    /**
     * Address errors.
     */
    class _VM68KAPI_PUBLIC address_error: public memory_exception
    {
    public:

        // Constructors.

        address_error(function_code fc, memory_map::address_type address)
            noexcept;


        const char *what() const noexcept override;
    };
}

#endif
