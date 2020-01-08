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

class ByteTests : public TestFixture
{
    CPPUNIT_TEST_SUITE(ByteTests);
    CPPUNIT_TEST(testToInt);
    CPPUNIT_TEST(testToUint);
    CPPUNIT_TEST_SUITE_END();

private:
    using T = byte;

    T data;

public:
    void setUp() override
    {
        data = T();
    }

    void testToInt()
    {
        CPPUNIT_ASSERT_EQUAL(std::int8_t(0), data.to_int());
        data = T(0x01);
        CPPUNIT_ASSERT_EQUAL(std::int8_t(0x01), data.to_int());
        data = 0x7f;
        CPPUNIT_ASSERT_EQUAL(std::int8_t(0x7f), data.to_int());
        data = 0x80;
        CPPUNIT_ASSERT_EQUAL(std::int8_t(-0x80), data.to_int());
    }

    void testToUint()
    {
        CPPUNIT_ASSERT_EQUAL(std::uint8_t(0), data.to_uint());
        data = T(0x01);
        CPPUNIT_ASSERT_EQUAL(std::uint8_t(0x01), data.to_uint());
        data = 0x00;
        CPPUNIT_ASSERT_EQUAL(std::uint8_t(0x00), data.to_uint());
        data = 0xff;
        CPPUNIT_ASSERT_EQUAL(std::uint8_t(0xff), data.to_uint());
    }
};
CPPUNIT_TEST_SUITE_REGISTRATION(ByteTests);

class WordTests : public TestFixture
{
    CPPUNIT_TEST_SUITE(WordTests);
    CPPUNIT_TEST(testToInt);
    CPPUNIT_TEST(testToUint);
    CPPUNIT_TEST_SUITE_END();

private:
    using T = word;

    T data;

public:
    void setUp() override
    {
        data = T();
    }

    void testToInt()
    {
        CPPUNIT_ASSERT_EQUAL(std::int16_t(0), data.to_int());
        data = T(0x0102);
        CPPUNIT_ASSERT_EQUAL(std::int16_t(0x0102), data.to_int());
        data = 0x7fff;
        CPPUNIT_ASSERT_EQUAL(std::int16_t(0x7fff), data.to_int());
        data = 0x8000;
        CPPUNIT_ASSERT_EQUAL(std::int16_t(-0x8000), data.to_int());
    }

    void testToUint()
    {
        CPPUNIT_ASSERT_EQUAL(std::uint16_t(0), data.to_uint());
        data = T(0x0102);
        CPPUNIT_ASSERT_EQUAL(std::uint16_t(0x0102), data.to_uint());
        data = 0x0000;
        CPPUNIT_ASSERT_EQUAL(std::uint16_t(0x0000), data.to_uint());
        data = 0xffff;
        CPPUNIT_ASSERT_EQUAL(std::uint16_t(0xffff), data.to_uint());
    }
};
CPPUNIT_TEST_SUITE_REGISTRATION(WordTests);

class LongWordTests : public TestFixture
{
    CPPUNIT_TEST_SUITE(LongWordTests);
    CPPUNIT_TEST(testToInt);
    CPPUNIT_TEST(testToUint);
    CPPUNIT_TEST_SUITE_END();

private:
    using T = long_word;

    T data;

public:
    void setUp() override
    {
        data = T();
    }

    void testToInt()
    {
        CPPUNIT_ASSERT_EQUAL(std::int32_t(0), data.to_int());
        data = T(0x01020304);
        CPPUNIT_ASSERT_EQUAL(std::int32_t(0x01020304), data.to_int());
        data = 0x7fffffff;
        CPPUNIT_ASSERT_EQUAL(std::int32_t(0x7fffffff), data.to_int());
        data = 0x80000000;
        CPPUNIT_ASSERT_EQUAL(std::int32_t(-0x80000000), data.to_int());
    }

    void testToUint()
    {
        CPPUNIT_ASSERT_EQUAL(std::uint32_t(0), data.to_uint());
        data = T(0x01020304);
        CPPUNIT_ASSERT_EQUAL(std::uint32_t(0x01020304), data.to_uint());
        data = 0x00000000;
        CPPUNIT_ASSERT_EQUAL(std::uint32_t(0x00000000), data.to_uint());
        data = 0xffffffff;
        CPPUNIT_ASSERT_EQUAL(std::uint32_t(0xffffffff), data.to_uint());
    }
};
CPPUNIT_TEST_SUITE_REGISTRATION(LongWordTests);
