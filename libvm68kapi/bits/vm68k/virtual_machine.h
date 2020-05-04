// <bits/vm68k/virtual_machine.h>
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

#ifndef _VM68K_VIRTUAL_MACHINE_H
#define _VM68K_VIRTUAL_MACHINE_H 1

#include <bits/vm68kapi.h>
#include <vm68k/memory>
#include <memory>

namespace vm68k
{
    /// Abstract device.
    class _VM68K_API_PUBLIC device
    {
    protected:
        device();

        // To make this class not copyable.
        device(const device &) = delete;
        device &operator =(const device &) = delete;

    public:
        virtual ~device() = 0;

    public:
        virtual void install(const std::shared_ptr<memory_map> &memory_map);
    };

    /// Virtual machine.
    class _VM68K_API_PUBLIC virtual_machine
    {
    private:
        std::shared_ptr<memory_map> _memory_map;

    public:
        explicit virtual_machine(const std::shared_ptr<memory_map> &memory_map);

        // To make this class not copyable.
        virtual_machine(const virtual_machine &) = delete;
        virtual_machine &operator =(const virtual_machine &) = delete;

    public:
        virtual ~virtual_machine();

    public:
        void add_device(std::unique_ptr<device> &&d);
    };
}

#endif
