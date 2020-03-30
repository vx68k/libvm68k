// testmemory.cpp
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

using namespace vm68k;
using CppUnit::TestFixture;

namespace
{
    class test_memory_map final : public memory_map
    {
    public:
        void read(mode, address_type, size_type, void *) override
        {
        }

        void write(mode, address_type, size_type, const void *) override
        {
        }
    };
}

class MemoryStaticTests: public TestFixture
{
    CPPUNIT_TEST_SUITE(MemoryStaticTests);
    CPPUNIT_TEST(testMemory);
    CPPUNIT_TEST(testReadWriteMemory);
    CPPUNIT_TEST_SUITE_END();

public:
    void testMemory()
    {
        CPPUNIT_ASSERT(!std::is_copy_constructible<memory>::value);
        CPPUNIT_ASSERT(!std::is_move_constructible<memory>::value);
        CPPUNIT_ASSERT(!std::is_copy_assignable<memory>::value);
        CPPUNIT_ASSERT(!std::is_move_assignable<memory>::value);
        CPPUNIT_ASSERT(std::has_virtual_destructor<memory>::value);
    }

    void testReadWriteMemory()
    {
        CPPUNIT_ASSERT((std::is_constructible<read_write_memory, std::size_t>::value));
        CPPUNIT_ASSERT(!std::is_copy_constructible<read_write_memory>::value);
        CPPUNIT_ASSERT(!std::is_move_constructible<read_write_memory>::value);
        CPPUNIT_ASSERT(!std::is_copy_assignable<read_write_memory>::value);
        CPPUNIT_ASSERT(!std::is_move_assignable<read_write_memory>::value);
        CPPUNIT_ASSERT(std::has_virtual_destructor<read_write_memory>::value);
    }
};
CPPUNIT_TEST_SUITE_REGISTRATION(MemoryStaticTests);

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
