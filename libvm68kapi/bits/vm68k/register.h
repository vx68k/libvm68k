// <bits/vm68k/register.h>
// Copyright (C) 2020 Kaz Nishimura
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

#ifndef _VM68K_REGISTER_H
#define _VM68K_REGISTER_H 1

#include <bits/vm68kapi.h>
#include <array>
#include <utility>
#include <cstdint>

namespace vm68k
{
    class _VM68KAPI_PUBLIC physical_register
    {
    public:
        /**
         * Use-counting pointers.
         *
         * This class should work as 'std::shared_ptr'.
         */
        class _VM68KAPI_PUBLIC pointer
        {
        private:
            physical_register *_ptr = nullptr;

        public:
            pointer() noexcept = default;

            explicit pointer(physical_register *x) noexcept
            :
                _ptr {x}
            {
                if (_ptr != nullptr) {
                    (_ptr->_use_count)++;
                }
            }

            pointer(const pointer &other) noexcept
            :
                pointer(other.get())
            {
                // Nothing to do.
            }

            pointer(pointer &&other) noexcept
            {
                swap(other);
            }

        public:
            ~pointer() noexcept
            {
                if (_ptr != nullptr) {
                    (_ptr->_use_count)--;
                }
            }

        public:
            void swap(pointer &other) noexcept
            {
                std::swap(_ptr, other._ptr);
            }

        public:
            physical_register *get() const noexcept
            {
                return _ptr;
            }

        public:
            physical_register &operator *() const noexcept
            {
                return *_ptr;
            }

        public:
            physical_register *operator ->() const noexcept
            {
                return _ptr;
            }
        };

    private:
        std::uint32_t _value = 0;

        unsigned int _use_count = 0;

    public:
        physical_register() noexcept = default;

        physical_register(const physical_register &) = delete;

    public:
        void operator =(const physical_register &) = delete;

    public:
        explicit constexpr operator std::uint32_t() const noexcept
        {
            return _value;
        }

    public:
        constexpr unsigned int use_count() const
        {
            return _use_count;
        }
    };

    /**
     * Data registers.
     */
    class _VM68KAPI_PUBLIC data_register
    {
    private:
        physical_register::pointer _physical;
    };

    /**
     * Register files.
     */
    class _VM68KAPI_PUBLIC register_file
    {
    private:
        std::array<physical_register, 32> _physical_registers;
    };
}

#endif
