/*
 * testmemory - test fixtures for the vx68kmemory unit in libvm68k
 * Copyright (C) 2012-2014 Kaz Nishimura
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#if HAVE_CONFIG_H
#include <config.h>
#endif
#if __BORLANDC__
#pragma hdrstop
#endif

#include <vm68k/memory>

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>
#include <memory>

using namespace std;
using namespace vm68k;
using CppUnit::TestFixture;

/*
 * Tests for 'memory_map'.
 */
class MemoryMapTests : public TestFixture {
    CPPUNIT_TEST_SUITE(MemoryMapTests);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp() override {
        memory = make_shared<memory_map>();
    }

    void tearDown() override {
        memory.reset();
    }

protected:
    shared_ptr<memory_map> memory;
};
CPPUNIT_TEST_SUITE_REGISTRATION(MemoryMapTests);
