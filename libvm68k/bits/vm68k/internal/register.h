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

#ifndef _VM68K_INTERNAL_REGISTER_H
#define _VM68K_INTERNAL_REGISTER_H 1

#include <vm68k/register>
#include <bits/vm68kcore.h>
#include <utility>
#include <cstdint>

namespace vm68k
{
    /**
     * Physical registers.
     */
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
                pointer(other._ptr)
            {
                // Nothing to do.
            }

            pointer(pointer &&other) noexcept
            {
                swap(other);
            }

        public:
            pointer &operator =(const pointer &other) noexcept
            {
                if (this != &other) {
                    if (_ptr != nullptr) {
                        (_ptr->_use_count)--;
                    }
                    _ptr = other._ptr;
                    if (_ptr != nullptr) {
                        (_ptr->_use_count)++;
                    }
                }
                return *this;
            }

            pointer &operator =(pointer &&other) noexcept
            {
                swap(other);
                return *this;
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
        constexpr explicit operator std::uint32_t() const noexcept
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
    class _VM68K_PUBLIC data_register
    {
    private:
        physical_register::pointer _physical;
    };

    /**
     * Address registers.
     */
    class _VM68K_PUBLIC address_register
    {
    private:
        physical_register::pointer _physical;
    };

    class _VM68K_PUBLIC d_register
    {
    private:
        std::uint32_t _value;

    public:
        d_register() = default;
    };

    class _VM68K_PUBLIC a_register
    {
    private:
        std::uint32_t _value;

    public:
        a_register() = default;
    };

    class _VM68K_PUBLIC runtime_register_file: public register_file
    {
    public:
        long_word d(int regno) const override;

        void set_d(int regno, long_word value) override;

        void set_d(int regno, word value) override;

        void set_d(int regno, byte) override;

    public:
        long_word a(int regno) const override;

        void set_a(int regno, long_word value) override;
    };
}

#endif
