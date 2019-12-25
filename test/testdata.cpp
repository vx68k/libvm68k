/*
 * testdata - test fixtures for the vx68kdata unit in libvm68k
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
#undef _GNU_SOURCE

#include <bits/vm68k/data.h>

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>

using namespace std;
using namespace vm68k;
using CppUnit::TestFixture;

/*
 * Tests for 'basic_data'.
 */
class DataTests : public TestFixture {
    CPPUNIT_TEST_SUITE(DataTests);
    CPPUNIT_TEST(testByteBasic);
    CPPUNIT_TEST(testWordBasic);
    CPPUNIT_TEST(testLongWordBasic);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp() override {
    }

    void tearDown() override {
    }

    void testByteBasic() {
        CPPUNIT_ASSERT_EQUAL(1U, byte_data::size());
        CPPUNIT_ASSERT_EQUAL(int8_t(0), byte_data().to_int());
        CPPUNIT_ASSERT_EQUAL(int8_t(0), byte_data(0).to_int());
        CPPUNIT_ASSERT_EQUAL(int8_t(0x7f), byte_data(0x7f).to_int());
        CPPUNIT_ASSERT_EQUAL(int8_t(-0x80), byte_data(0x80).to_int());
        CPPUNIT_ASSERT_EQUAL(int8_t(-1), byte_data(0xff).to_int());
        CPPUNIT_ASSERT_EQUAL(uint8_t(0), byte_data().to_uint());
        CPPUNIT_ASSERT_EQUAL(uint8_t(0), byte_data(0).to_uint());
        CPPUNIT_ASSERT_EQUAL(uint8_t(0xff), byte_data(0xff).to_uint());
    }

    void testWordBasic() {
        CPPUNIT_ASSERT_EQUAL(2U, word_data::size());
        CPPUNIT_ASSERT_EQUAL(int16_t(0), word_data().to_int());
        CPPUNIT_ASSERT_EQUAL(int16_t(0), word_data(0).to_int());
        CPPUNIT_ASSERT_EQUAL(int16_t(0x7fff), word_data(0x7fff).to_int());
        CPPUNIT_ASSERT_EQUAL(int16_t(-0x8000), word_data(0x8000).to_int());
        CPPUNIT_ASSERT_EQUAL(int16_t(-1), word_data(0xffff).to_int());
        CPPUNIT_ASSERT_EQUAL(uint16_t(0), word_data().to_uint());
        CPPUNIT_ASSERT_EQUAL(uint16_t(0), word_data(0).to_uint());
        CPPUNIT_ASSERT_EQUAL(uint16_t(0xffff), word_data(0xffff).to_uint());
    }

    void testLongWordBasic() {
        CPPUNIT_ASSERT_EQUAL(4U, long_word_data::size());
        CPPUNIT_ASSERT_EQUAL(int32_t(0), long_word_data().to_int());
        CPPUNIT_ASSERT_EQUAL(int32_t(0), long_word_data(0).to_int());
        CPPUNIT_ASSERT_EQUAL(int32_t(0x7fffffffL),
                long_word_data(0x7fffffffL).to_int());
        CPPUNIT_ASSERT_EQUAL(int32_t(-0x80000000L),
                long_word_data(0x80000000L).to_int());
        CPPUNIT_ASSERT_EQUAL(int32_t(-1),
                long_word_data(0xffffffffL).to_int());
        CPPUNIT_ASSERT_EQUAL(uint32_t(0), long_word_data().to_uint());
        CPPUNIT_ASSERT_EQUAL(uint32_t(0), long_word_data(0).to_uint());
        CPPUNIT_ASSERT_EQUAL(uint32_t(0xffffffffL),
                long_word_data(0xffffffffL).to_uint());
    }
};
CPPUNIT_TEST_SUITE_REGISTRATION(DataTests);
