// virtual_machine.cpp
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

#if HAVE_CONFIG_H
#include <config.h>
#endif
#if __BORLANDC__
#pragma hdrstop
#endif

#include <bits/vm68k/virtual_machine.h>

#if __BORLANDC__
#pragma package(smart_init)
#endif

using namespace vm68k;

// Class 'device' implementation.

device::device()
{
}

device::~device()
{
}

void device::install(const std::shared_ptr<memory_map> &)
{
    // Empty.
}

// Class 'virtual_machine' implementation.

virtual_machine::virtual_machine(const std::shared_ptr<memory_map> &memory_map)
    : _memory_map(memory_map)
{
}

virtual_machine::~virtual_machine()
{
}

void virtual_machine::add_device(std::unique_ptr<device> &&d)
{
    d.reset(); // TODO: Replace with device registration code.
}
