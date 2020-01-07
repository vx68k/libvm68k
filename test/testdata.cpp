// testdata.cpp
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

#include <vm68k/data>

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>
#include <type_traits>

using namespace vm68k;
using CppUnit::TestFixture;

// Tests for static properties.
class DataStaticTests : public TestFixture
{
    CPPUNIT_TEST_SUITE(DataStaticTests);
    CPPUNIT_TEST(testByteType);
    CPPUNIT_TEST(testWordType);
    CPPUNIT_TEST(testLongWordType);
    CPPUNIT_TEST_SUITE_END();

public:
    void testByteType()
    {
        using T = byte;
        CPPUNIT_ASSERT_EQUAL(true, std::is_trivial<T>::value);
        CPPUNIT_ASSERT_EQUAL(true, std::is_standard_layout<T>::value);
        CPPUNIT_ASSERT_EQUAL(std::size_t(1), T::size());
    }

    void testWordType()
    {
        using T = word;
        CPPUNIT_ASSERT_EQUAL(true, std::is_trivial<T>::value);
        CPPUNIT_ASSERT_EQUAL(true, std::is_standard_layout<T>::value);
        CPPUNIT_ASSERT_EQUAL(std::size_t(2), T::size());
    }

    void testLongWordType()
    {
        using T = long_word;
        CPPUNIT_ASSERT_EQUAL(true, std::is_trivial<T>::value);
        CPPUNIT_ASSERT_EQUAL(true, std::is_standard_layout<T>::value);
        CPPUNIT_ASSERT_EQUAL(std::size_t(4), T::size());
    }
};
CPPUNIT_TEST_SUITE_REGISTRATION(DataStaticTests);

/*
 * Tests for data types.
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
        CPPUNIT_ASSERT_EQUAL(std::size_t(1U), byte::size());
        CPPUNIT_ASSERT_EQUAL(std::int8_t(0), byte().to_int());
        CPPUNIT_ASSERT_EQUAL(std::int8_t(0), byte(0).to_int());
        CPPUNIT_ASSERT_EQUAL(std::int8_t(0x7f), byte(0x7f).to_int());
        CPPUNIT_ASSERT_EQUAL(std::int8_t(-0x80), byte(0x80).to_int());
        CPPUNIT_ASSERT_EQUAL(std::int8_t(-1), byte(0xff).to_int());
        CPPUNIT_ASSERT_EQUAL(std::uint8_t(0), byte().to_uint());
        CPPUNIT_ASSERT_EQUAL(std::uint8_t(0), byte(0).to_uint());
        CPPUNIT_ASSERT_EQUAL(std::uint8_t(0xff), byte(0xff).to_uint());
    }

    void testWordBasic() {
        CPPUNIT_ASSERT_EQUAL(std::size_t(2U), word::size());
        CPPUNIT_ASSERT_EQUAL(std::int16_t(0), word().to_int());
        CPPUNIT_ASSERT_EQUAL(std::int16_t(0), word(0).to_int());
        CPPUNIT_ASSERT_EQUAL(std::int16_t(0x7fff), word(0x7fff).to_int());
        CPPUNIT_ASSERT_EQUAL(std::int16_t(-0x8000), word(0x8000).to_int());
        CPPUNIT_ASSERT_EQUAL(std::int16_t(-1), word(0xffff).to_int());
        CPPUNIT_ASSERT_EQUAL(std::uint16_t(0), word().to_uint());
        CPPUNIT_ASSERT_EQUAL(std::uint16_t(0), word(0).to_uint());
        CPPUNIT_ASSERT_EQUAL(std::uint16_t(0xffff), word(0xffff).to_uint());
    }

    void testLongWordBasic() {
        CPPUNIT_ASSERT_EQUAL(std::size_t(4U), long_word::size());
        CPPUNIT_ASSERT_EQUAL(std::int32_t(0), long_word().to_int());
        CPPUNIT_ASSERT_EQUAL(std::int32_t(0), long_word(0).to_int());
        CPPUNIT_ASSERT_EQUAL(std::int32_t(0x7fffffffL),
                long_word(0x7fffffffL).to_int());
        CPPUNIT_ASSERT_EQUAL(std::int32_t(-0x80000000L),
                long_word(0x80000000L).to_int());
        CPPUNIT_ASSERT_EQUAL(std::int32_t(-1),
                long_word(0xffffffffL).to_int());
        CPPUNIT_ASSERT_EQUAL(std::uint32_t(0), long_word().to_uint());
        CPPUNIT_ASSERT_EQUAL(std::uint32_t(0), long_word(0).to_uint());
        CPPUNIT_ASSERT_EQUAL(std::uint32_t(0xffffffffL),
                long_word(0xffffffffL).to_uint());
    }
};
CPPUNIT_TEST_SUITE_REGISTRATION(DataTests);
