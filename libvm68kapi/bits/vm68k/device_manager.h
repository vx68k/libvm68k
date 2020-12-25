// <bits/vm68k/device_manager.h>
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

#ifndef _VM68K_DEVICE_MANAGER_H
#define _VM68K_DEVICE_MANAGER_H 1

#include <bits/vm68kapidef.h>
#include <vm68k/memory>
#include <unordered_set>
#include <memory>

namespace vm68k
{
    /**
     * Device managers.
     */
    class _VM68KAPI_PUBLIC device_manager
    {
    public:
        /**
         * Base class for devices.
         */
        class _VM68KAPI_PUBLIC device
        {
        protected:
            device() = default;

            device(const device &other) = default;

        public:
            virtual ~device() = default;

        public:
            /**
             * Maps the device on a memory map.
             */
            virtual void map(memory_map &memory) = 0;
        };

    private:
        std::shared_ptr<memory_map> _memory;

    private:
        std::unordered_set<std::shared_ptr<device>> _devices;

    public:
        /**
         * Constructor.
         */
        explicit device_manager(const std::shared_ptr<memory_map> &memory);

        /**
         * Deleted copy constructor.
         */
        device_manager(const device_manager &other) = delete;

        /**
         * Move constructor.
         */
        device_manager(device_manager &&other) noexcept;

    public:
        virtual ~device_manager();

    public:
        /**
         * Deleted copy assignment operator.
         */
        void operator =(const device_manager &other) = delete;

        /**
         * Move assignment operator.
         */
        device_manager &operator =(device_manager &&other) noexcept
        {
            swap(other);
            return *this;
        }

    public:
        /**
         * Swaps the contents with another.
         */
        void swap(device_manager &other) noexcept;

    public:
        /**
         * Returns the memory map associated to the device manager.
         */
        const std::shared_ptr<memory_map> &memory() const noexcept
        {
            return _memory;
        }

    public:
        /**
         * Adds a device to the device manager.
         */
        void add_device(const std::shared_ptr<device> &device);
    };

    /**
     * Swaps the contents of two device managers.
     */
    inline void swap(device_manager &one, device_manager &other) noexcept
    {
        one.swap(other);
    }
}

#endif
