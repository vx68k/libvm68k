// device_manager.cpp
// Copyright (C) 2020-2021 Kaz Nishimura
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

#include <bits/vm68k/device_manager.h>

#include <utility>

using std::get;
using std::shared_ptr;
using namespace vm68k;

device_manager::device_manager(const shared_ptr<memory_map> &memory)
:
    _memory {memory}
{
    // Nothing to do.
}

device_manager::~device_manager()
{
    // Nothing to do.
}

void device_manager::add_device(const shared_ptr<device> &device)
{
    auto &&inserted = _devices.insert(device);
    if (get<1>(inserted)) {
        device->map(*_memory);
    }
}
