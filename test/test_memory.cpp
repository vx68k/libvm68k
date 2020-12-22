// test_memory.cpp
// Copyright (C) 2012-2019 Kaz Nishimura
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

#include <vm68k/memory>

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>
#include <type_traits>
#include <memory>
#include <cstdint>

using std::uint32_t;
using std::unique_ptr;
using namespace vm68k;
using CppUnit::TestFixture;

namespace
{
    class test_memory_map final : public memory_map
    {
    public:
        void read(access_mode, address_type, size_type, void *) override
        {
        }

        void write(access_mode, address_type, size_type, const void *) override
        {
        }
    };
}

/*
 * Tests for 'memory_map'.
 */
class MemoryMapTests : public TestFixture {
    CPPUNIT_TEST_SUITE(MemoryMapTests);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp() override {
        memory = std::make_shared<test_memory_map>();
    }

    void tearDown() override {
        memory.reset();
    }

protected:
    std::shared_ptr<memory_map> memory;
};
CPPUNIT_TEST_SUITE_REGISTRATION(MemoryMapTests);

// Tests for class paged_memory_map.
class PagedMemoryMapTests: public TestFixture
{
    CPPUNIT_TEST_SUITE(PagedMemoryMapTests);
    CPPUNIT_TEST(testAddressMask);
    CPPUNIT_TEST(testPageSize);
    CPPUNIT_TEST_SUITE_END();

private:
    unique_ptr<paged_memory_map> _memory;

public:
    void setUp()
    {
        _memory.reset(new paged_memory_map(0xffffffU, 0x2000U));
    }

public:
    void tearDown()
    {
        _memory.reset();
    }

private:
    void testAddressMask()
    {
        CPPUNIT_ASSERT_EQUAL((memory_map::address_type)0xffffffU, _memory->address_mask());
    }

private:
    void testPageSize()
    {
        CPPUNIT_ASSERT_EQUAL((memory_map::size_type)0x2000U, _memory->page_size());
    }
};
CPPUNIT_TEST_SUITE_REGISTRATION(PagedMemoryMapTests);
