// device_manager.cpp
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

#include <bits/vm68k/device_manager.h>

#include <utility>

using std::move;
using std::shared_ptr;
using std::swap;
using namespace vm68k;

device_manager::device_manager(const shared_ptr<memory_map> &memory)
:
    _memory {memory}
{
    // Nothing to do.
}

device_manager::device_manager(shared_ptr<memory_map> &&memory)
:
    _memory {move(memory)}
{
    // Nothing to do.
}

device_manager::device_manager(device_manager &&other) noexcept
:
    _memory {move(other._memory)},
    _devices {move(other._devices)}
{
    // Nothing to do.
}

device_manager::~device_manager()
{
    // Nothing to do.
}

void device_manager::swap(device_manager &other) noexcept
{
    if (this != &other) {
        ::swap(_memory, other._memory);
        ::swap(_devices, other._devices);
    }
}

void device_manager::add_device(const shared_ptr<device> &device)
{
    auto &&inserted = _devices.insert(device);
    if (inserted.second) {
        device->map(*_memory);
    }
}
