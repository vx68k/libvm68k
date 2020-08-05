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
        void read(mode mode, address_type address, size_type size,
            void *buffer) override
        {
            _memory->read(mode, address, size, buffer);
        }

        void write(mode mode, address_type address, size_type size,
            const void *buffer) override
        {
            _memory->write(mode, address, size, buffer);
        }
    };
}

/*
 * Tests for class 'context'.
 */
class ContextTests : public TestFixture {
    CPPUNIT_TEST_SUITE(ContextTests);
    CPPUNIT_TEST(testMemory);
    CPPUNIT_TEST_SUITE_END();

private:
    shared_ptr<runtime_execution_context> _context;

public:
    void setUp() override {
        auto memory = make_shared<test_memory_map>();
        _context.reset(new runtime_execution_context(memory, long_word(0)));
    }

    void tearDown() override {
        _context.reset();
    }

    void testMemory() {
        CPPUNIT_ASSERT(_context->memory() != NULL);
    }
};
CPPUNIT_TEST_SUITE_REGISTRATION(ContextTests);
