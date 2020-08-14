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

#include <vm68k/runtime>

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
    CPPUNIT_TEST(testReadWriteMemory);
    CPPUNIT_TEST_SUITE_END();

public:
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

// Unit test for 'read_write_memory'.
class ReadWriteMemoryTest: public TestFixture
{
    CPPUNIT_TEST_SUITE(ReadWriteMemoryTest);
    CPPUNIT_TEST(testSize);
    CPPUNIT_TEST(testReadWrite);
    CPPUNIT_TEST_SUITE_END();

private:
    unique_ptr<read_write_memory> memory;

public:
    void setUp() final override
    {
        memory.reset(new read_write_memory(0x10000U));
    }

public:
    void tearDown() final override
    {
        memory.reset();
    }

private:
    void testSize()
    {
        CPPUNIT_ASSERT_EQUAL(memory_map::size_type(0x10000U), memory->size());
    }

    void testReadWrite()
    {
        memory->relocate(0x10000U);

        const uint32_t value1 = 0x81828384;
        uint32_t value2 = 0;
        memory->write(memory_map::mode::SUPERVISOR, 0x10000U, sizeof value1, &value1);
        memory->read(memory_map::mode::SUPERVISOR, 0x10000U, sizeof value2, &value2);
        CPPUNIT_ASSERT_EQUAL(value1, value2);
    }
};
CPPUNIT_TEST_SUITE_REGISTRATION(ReadWriteMemoryTest);
