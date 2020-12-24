// test_runtime.cpp
// Copyright (C) 2012-2020 Kaz Nishimura
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
#include <memory>
#include <utility>

using std::unique_ptr;
using std::shared_ptr;
using std::make_shared;
using CppUnit::TestFixture;
using namespace vm68k;

namespace
{
    class test_memory_map final : public memory_map
    {
        using inherited = memory_map;

    private:
        unique_ptr<read_write_memory> _memory;

    public:
        test_memory_map()
            : _memory {new read_write_memory(0x10000)}
        {
        }

    public:
        void read(function_code fc, address_type address, size_type size,
            void *buffer) override
        {
            _memory->read(fc, address, size, buffer);
        }

        void write(function_code fc, address_type address, size_type size,
            const void *buffer) override
        {
            _memory->write(fc, address, size, buffer);
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
        memory->write(memory_map::function_code::data, 0x10000U, sizeof value1, &value1);
        memory->read(memory_map::function_code::data, 0x10000U, sizeof value2, &value2);
        CPPUNIT_ASSERT_EQUAL(value1, value2);
    }
};
CPPUNIT_TEST_SUITE_REGISTRATION(ReadWriteMemoryTest);

/*
 * Tests for class execution_context.
 */
class ExecutionContextTests: public TestFixture
{
    CPPUNIT_TEST_SUITE(ExecutionContextTests);
    CPPUNIT_TEST(testMemory);
    CPPUNIT_TEST(testDataRegister);
    CPPUNIT_TEST(testAddressRegister);
    CPPUNIT_TEST(testRead);
    CPPUNIT_TEST(testWrite);
    CPPUNIT_TEST_SUITE_END();

private:
    shared_ptr<execution_context> _context;

public:
    void setUp() override
    {
        auto memory = make_shared<test_memory_map>();
        _context.reset(new execution_context(memory));
    }

public:
    void tearDown() override
    {
        _context.reset();
    }

private:
    void testMemory()
    {
        CPPUNIT_ASSERT(_context->memory() != NULL);
    }

private:
    void testDataRegister()
    {
        _context->d(0) = long_word(0x01234567);
        _context->d(1) = long_word(0);
        CPPUNIT_ASSERT_EQUAL(long_word::uint_type(0x01234567U), long_word(_context->d(0)).to_uint());

        _context->d(0) = long_word(0x01234567);
        _context->d(0) = word(0x89ab);
        CPPUNIT_ASSERT_EQUAL(long_word::uint_type(0x012389abU), long_word(_context->d(0)).to_uint());
        CPPUNIT_ASSERT_EQUAL(word::uint_type(0x89abU), word(_context->d(0)).to_uint());

        _context->d(0) = long_word(0x01234567);
        _context->d(0) = byte(0x89);
        CPPUNIT_ASSERT_EQUAL(long_word::uint_type(0x01234589U), long_word(_context->d(0)).to_uint());
        CPPUNIT_ASSERT_EQUAL(byte::uint_type(0x89U), byte(_context->d(0)).to_uint());
    }

private:
    void testAddressRegister()
    {
        _context->a(0) = long_word(0x01234567);
        _context->a(1) = long_word(0);
        CPPUNIT_ASSERT_EQUAL(long_word::uint_type(0x01234567U), long_word(_context->a(0)).to_uint());

        _context->a(0) = long_word(0x01234567);
        _context->a(0) = word(0x0123);
        CPPUNIT_ASSERT_EQUAL(long_word::uint_type(0x00000123U), long_word(_context->a(0)).to_uint());
        CPPUNIT_ASSERT_EQUAL(word::uint_type(0x0123U), word(_context->a(0)).to_uint());

        _context->a(0) = long_word(0x01234567);
        _context->a(0) = word(0x89ab);
        CPPUNIT_ASSERT_EQUAL(long_word::uint_type(0xffff89abU), long_word(_context->a(0)).to_uint());
        CPPUNIT_ASSERT_EQUAL(word::uint_type(0x89abU), word(_context->a(0)).to_uint());
    }

private:
    void testRead()
    {
        const unsigned char bytes[] {0x89U, 0xabU, 0xcdU, 0xefU};
        _context->memory()->write(memory_map::function_code::data, 0x8000U, 4U, bytes);

        long_word data1;
        _context->read(long_word(0x8000U), data1);
        CPPUNIT_ASSERT_EQUAL(uint32_t(0x89abcdefU), data1.to_uint());
    }

private:
    void testWrite()
    {
        long_word data1 {0x89abcdefU};
        _context->write(long_word(0x8000U), data1);

        unsigned char bytes[4U];
        _context->memory()->read(memory_map::function_code::data, 0x8000U, 4U, bytes);
        CPPUNIT_ASSERT_EQUAL((unsigned char)0x89U, bytes[0]);
        CPPUNIT_ASSERT_EQUAL((unsigned char)0xabU, bytes[1]);
        CPPUNIT_ASSERT_EQUAL((unsigned char)0xcdU, bytes[2]);
        CPPUNIT_ASSERT_EQUAL((unsigned char)0xefU, bytes[3]);
    }
};
CPPUNIT_TEST_SUITE_REGISTRATION(ExecutionContextTests);
