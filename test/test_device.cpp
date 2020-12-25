// test_device.cpp
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

#include <vm68k/device>

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>

using std::shared_ptr;
using std::make_shared;
using CppUnit::TestFixture;
using namespace vm68k;


/*
 * Tests for class device_manager.
 */
class DeviceManagerTests: public TestFixture
{
    CPPUNIT_TEST_SUITE(DeviceManagerTests);
    CPPUNIT_TEST(testMemory);
    CPPUNIT_TEST_SUITE_END();

private:
    shared_ptr<memory_map> _memory_map;
    shared_ptr<device_manager> _device_manager;

public:
    virtual void setUp() override
    {
        _memory_map = make_shared<paged_memory_map>();
        _device_manager = make_shared<device_manager>(_memory_map);
    }

public:
    virtual void tearDown() override
    {
        _device_manager.reset();
        _memory_map.reset();
    }

private:
    void testMemory()
    {
        CPPUNIT_ASSERT(_memory_map == _device_manager->memory());
    }
};
CPPUNIT_TEST_SUITE_REGISTRATION(DeviceManagerTests);
