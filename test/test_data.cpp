// test_data.cpp
// Copyright (C) 2012-2021 Kaz Nishimura
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

#include <vm68k/data>

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>
#include <iterator>
#include <type_traits>
#include <cstdint>

using std::size_t;
using std::ptrdiff_t;
using std::int8_t;
using std::int16_t;
using std::int32_t;
using std::uint8_t;
using std::uint16_t;
using std::uint32_t;
using std::is_trivial;
using std::is_standard_layout;
using std::is_constructible;
using std::is_assignable;
using std::distance;
using namespace vm68k;
using CppUnit::TestFixture;

// Test case for the static properties of the data types.
class DataStaticTests : public TestFixture
{
    CPPUNIT_TEST_SUITE(DataStaticTests);
    CPPUNIT_TEST(testByteType);
    CPPUNIT_TEST(testWordType);
    CPPUNIT_TEST(testLongWordType);
    CPPUNIT_TEST_SUITE_END();

public:
    /// Tests the static properties of 'byte'.
    void testByteType()
    {
        using T = byte;
        CPPUNIT_ASSERT_EQUAL(true, is_trivial<T>::value);
        CPPUNIT_ASSERT_EQUAL(true, is_standard_layout<T>::value);
        CPPUNIT_ASSERT_EQUAL(true, (is_constructible<T, uint8_t>::value));
        CPPUNIT_ASSERT_EQUAL(size_t(1), T::size());
    }

    /// Tests the static properties of 'word'.
    void testWordType()
    {
        using T = word;
        CPPUNIT_ASSERT_EQUAL(true, is_trivial<T>::value);
        CPPUNIT_ASSERT_EQUAL(true, is_standard_layout<T>::value);
        CPPUNIT_ASSERT_EQUAL(true, (is_constructible<T, uint16_t>::value));
        CPPUNIT_ASSERT_EQUAL(size_t(2), T::size());
    }

    /// Tests the static properties of 'long_word'.
    void testLongWordType()
    {
        using T = long_word;
        CPPUNIT_ASSERT_EQUAL(true, is_trivial<T>::value);
        CPPUNIT_ASSERT_EQUAL(true, is_standard_layout<T>::value);
        CPPUNIT_ASSERT_EQUAL(true, (is_constructible<T, uint32_t>::value));
        CPPUNIT_ASSERT_EQUAL(size_t(4), T::size());
    }
};
CPPUNIT_TEST_SUITE_REGISTRATION(DataStaticTests);

class ByteTests : public TestFixture
{
    CPPUNIT_TEST_SUITE(ByteTests);
    CPPUNIT_TEST(testToInt);
    CPPUNIT_TEST(testToUint);
    CPPUNIT_TEST(testSerialize);
    CPPUNIT_TEST(testDeserialize);
    CPPUNIT_TEST_SUITE_END();

private:

    byte data;

public:

    void setUp() override
    {
        data = byte();
    }

    void testToInt()
    {
        CPPUNIT_ASSERT_EQUAL(int8_t(0), data.to_int());
        data = 0x01_b;
        CPPUNIT_ASSERT_EQUAL(int8_t(0x01), data.to_int());
        data = 0x7f_b;
        CPPUNIT_ASSERT_EQUAL(int8_t(0x7f), data.to_int());
        data = 0x80_b;
        CPPUNIT_ASSERT_EQUAL(int8_t(-0x80), data.to_int());
    }

    void testToUint()
    {
        CPPUNIT_ASSERT_EQUAL(uint8_t(0), data.to_uint());
        data = 0x01_b;
        CPPUNIT_ASSERT_EQUAL(uint8_t(0x01), data.to_uint());
        data = 0x00_b;
        CPPUNIT_ASSERT_EQUAL(uint8_t(0x00), data.to_uint());
        data = 0xff_b;
        CPPUNIT_ASSERT_EQUAL(uint8_t(0xff), data.to_uint());
    }

    void testSerialize()
    {
        data = 0x81_b;
        int serial[byte::size()] = {};
        auto end = data.serialize(serial);
        CPPUNIT_ASSERT_EQUAL(ptrdiff_t(1), distance(serial, end));
        CPPUNIT_ASSERT_EQUAL(0x81, serial[0]);
    }

    /// Tests 'byte::deserialize'.
    void testDeserialize()
    {
        const int serial[] = {0x81};
        auto end = data.deserialize(serial);
        CPPUNIT_ASSERT_EQUAL(ptrdiff_t(1), distance(serial, end));
        CPPUNIT_ASSERT_EQUAL(uint8_t(0x81), data.to_uint());
    }
};
CPPUNIT_TEST_SUITE_REGISTRATION(ByteTests);

class WordTests : public TestFixture
{
    CPPUNIT_TEST_SUITE(WordTests);
    CPPUNIT_TEST(testToInt);
    CPPUNIT_TEST(testToUint);
    CPPUNIT_TEST(testSerialize);
    CPPUNIT_TEST(testDeserialize);
    CPPUNIT_TEST_SUITE_END();

private:

    word data;

public:

    void setUp() override
    {
        data = word();
    }

    void testToInt()
    {
        CPPUNIT_ASSERT_EQUAL(int16_t(0), data.to_int());
        data = 0x0102_w;
        CPPUNIT_ASSERT_EQUAL(int16_t(0x0102), data.to_int());
        data = 0x7fff_w;
        CPPUNIT_ASSERT_EQUAL(int16_t(0x7fff), data.to_int());
        data = 0x8000_w;
        CPPUNIT_ASSERT_EQUAL(int16_t(-0x8000), data.to_int());
    }

    void testToUint()
    {
        CPPUNIT_ASSERT_EQUAL(uint16_t(0), data.to_uint());
        data = 0x0102_w;
        CPPUNIT_ASSERT_EQUAL(uint16_t(0x0102), data.to_uint());
        data = 0x0000_w;
        CPPUNIT_ASSERT_EQUAL(uint16_t(0x0000), data.to_uint());
        data = 0xffff_w;
        CPPUNIT_ASSERT_EQUAL(uint16_t(0xffff), data.to_uint());
    }

    void testSerialize()
    {
        data = 0x8182_w;
        int serial[word::size()] = {};
        auto end = data.serialize(serial);
        CPPUNIT_ASSERT_EQUAL(ptrdiff_t(2), distance(serial, end));
        CPPUNIT_ASSERT_EQUAL(0x81, serial[0]);
        CPPUNIT_ASSERT_EQUAL(0x82, serial[1]);
    }

    /// Tests 'word::deserialize'.
    void testDeserialize()
    {
        const int serial[] = {0x81, 0x82};
        auto end = data.deserialize(serial);
        CPPUNIT_ASSERT_EQUAL(ptrdiff_t(2), distance(serial, end));
        CPPUNIT_ASSERT_EQUAL(uint16_t(0x8182), data.to_uint());
    }

};
CPPUNIT_TEST_SUITE_REGISTRATION(WordTests);

class LongWordTests : public TestFixture
{
    CPPUNIT_TEST_SUITE(LongWordTests);
    CPPUNIT_TEST(testToInt);
    CPPUNIT_TEST(testToUint);
    CPPUNIT_TEST(testSerialize);
    CPPUNIT_TEST(testDeserialize);
    CPPUNIT_TEST_SUITE_END();

private:

    long_word data;

public:

    void setUp() override
    {
        data = long_word();
    }

    void testToInt()
    {
        CPPUNIT_ASSERT_EQUAL(int32_t(0), data.to_int());
        data = 0x01020304_l;
        CPPUNIT_ASSERT_EQUAL(int32_t(0x01020304), data.to_int());
        data = 0x7fffffff_l;
        CPPUNIT_ASSERT_EQUAL(int32_t(0x7fffffff), data.to_int());
        data = 0x80000000_l;
        CPPUNIT_ASSERT_EQUAL(int32_t(-0x80000000), data.to_int());
    }

    void testToUint()
    {
        CPPUNIT_ASSERT_EQUAL(uint32_t(0), data.to_uint());
        data = 0x01020304_l;
        CPPUNIT_ASSERT_EQUAL(uint32_t(0x01020304), data.to_uint());
        data = 0x00000000_l;
        CPPUNIT_ASSERT_EQUAL(uint32_t(0x00000000), data.to_uint());
        data = 0xffffffff_l;
        CPPUNIT_ASSERT_EQUAL(uint32_t(0xffffffff), data.to_uint());
    }

    void testSerialize()
    {
        data = 0x81828384_l;
        int serial[long_word::size()] = {};
        auto end = data.serialize(serial);
        CPPUNIT_ASSERT_EQUAL(ptrdiff_t(4), distance(serial, end));
        CPPUNIT_ASSERT_EQUAL(0x81, serial[0]);
        CPPUNIT_ASSERT_EQUAL(0x82, serial[1]);
        CPPUNIT_ASSERT_EQUAL(0x83, serial[2]);
        CPPUNIT_ASSERT_EQUAL(0x84, serial[3]);
    }

    /// Tests 'long_word::deserialize'.
    void testDeserialize()
    {
        const int serial[] = {0x81, 0x82, 0x83, 0x84};
        auto end = data.deserialize(serial);
        CPPUNIT_ASSERT_EQUAL(ptrdiff_t(4), distance(serial, end));
        CPPUNIT_ASSERT_EQUAL(uint32_t(0x81828384), data.to_uint());
    }
};
CPPUNIT_TEST_SUITE_REGISTRATION(LongWordTests);
