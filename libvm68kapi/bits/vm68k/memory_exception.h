// <bits/vm68k/memory_exception.h>
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

#ifndef _VM68K_MEMORY_EXCEPTION_H
#define _VM68K_MEMORY_EXCEPTION_H 1

#include <bits/vm68k/memory_map.h>
#include <exception>

namespace vm68k
{
    class _VM68KAPI_PUBLIC memory_exception: public std::exception
    {
    public:
        using address_type = memory_map::address_type;

    private:
        address_type _fault_address;

    public:
        explicit memory_exception(address_type fault_address) noexcept;

        memory_exception(const memory_exception &other) noexcept;

    public:
        memory_exception &operator =(const memory_exception &other) noexcept;

    public:
        virtual ~memory_exception();

    public:
        address_type fault_address() const noexcept
        {
            return _fault_address;
        }

    public:
        const char *what() const noexcept override;
    };

    /**
     * Bus errors.
     */
    class _VM68KAPI_PUBLIC bus_error: public memory_exception
    {
    public:
        explicit bus_error(address_type fault_address) noexcept
        :
            memory_exception(fault_address)
        {
            // Nothing more to do.
        }

    public:
        const char *what() const noexcept override;
    };

    /**
     * Address errors.
     */
    class _VM68KAPI_PUBLIC address_error: public memory_exception
    {
    public:
        address_error(address_type fault_address) noexcept
        :
            memory_exception(fault_address)
        {
            // Nothing more to do.
        }

    public:
        const char *what() const noexcept override;
    };
}

#endif
