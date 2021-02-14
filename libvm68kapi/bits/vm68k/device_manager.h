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
#if _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

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

            // Constructors.

            device() = default;

            device(const device &) = delete;

        public:

            // Destructor.

            virtual ~device() = default;


            // Assignment operators.

            void operator =(const device &) = delete;


            /**
             * Maps the device on a memory map.
             */
            virtual void map(memory_map &memory) = 0;
        };

    private:

        std::shared_ptr<memory_map> _memory;

        std::unordered_set<std::shared_ptr<device>> _devices;

    public:

        // Constructors.

        /**
         * Constructor that copies a memory map pointer.
         */
        explicit device_manager(const std::shared_ptr<memory_map> &memory);

        /**
         * Constructor that moves a memory map pointer.
         */
        explicit device_manager(std::shared_ptr<memory_map> &&memory);

        /**
         * Deleted copy constructor.
         */
        device_manager(const device_manager &) = delete;


        // Destructor.

        virtual ~device_manager();


        // Assignment operators.

        /**
         * Deleted copy assignment operator.
         */
        void operator =(const device_manager &) = delete;


        /**
         * Returns the memory map associated to the device manager.
         */
        const std::shared_ptr<memory_map> &memory() const noexcept
        {
            return _memory;
        }

        /**
         * Adds a device to the device manager.
         */
        void add_device(const std::shared_ptr<device> &device);
    };

#if _MSC_VER
#pragma warning(pop)
#endif
}

#endif
