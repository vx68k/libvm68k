/*
 * Test_vm68kdata - Test cases for libvm68k (implementation)
 * Copyright (C) 2012  Kaz Sasa
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <System.hpp>
#pragma hdrstop

#include "Test_vm68kdata.h"

#include <vm68k>
#include <TestFramework.hpp>

using namespace vm68k;

template<typename DataT>
class TTest_basic_data : public TTestCase {
public:
    typedef DataT data_type;

    __fastcall TTest_basic_data(UnicodeString MethodName) : TTestCase(MethodName) {
    }

    virtual void __fastcall SetUp();
    virtual void __fastcall TearDown();

__published:
    void __fastcall Test_size();
    void __fastcall Test_min();
    void __fastcall Test_max();
    void __fastcall Test_umax();
    void __fastcall TestConstructor();
    void __fastcall TestEquals();
    void __fastcall TestNotEquals();
};

template<typename DataT>
void __fastcall TTest_basic_data<DataT>::SetUp() {
}

template<typename DataT>
void __fastcall TTest_basic_data<DataT>::TearDown() {
}

template<typename DataT>
void __fastcall TTest_basic_data<DataT>::TestConstructor() {
    const data_type zero1;
    const data_type zero2(0);
    const data_type max1(data_type::max());
    const data_type min1(data_type::min());
    const data_type umax1(data_type::umax());
    const data_type omax1(data_type::max() + 1);
    const data_type omin1(data_type::min() - 1);
    CheckEquals(0, zero1, "basic_data()");
    CheckEquals(0, zero2, "basic_data(0)");
    CheckEquals(data_type::max(), max1, "basic_data(max())");
    CheckEquals(data_type::min(), min1, "basic_data(min())");
    CheckEquals(-1, umax1, "basic_data(umax())");
    CheckEquals(data_type::min(), omax1, "basic_data(max() + 1)");
    CheckEquals(data_type::max(), omin1, "basic_data(min() - 1)");
}

template<typename DataT>
void __fastcall TTest_basic_data<DataT>::TestEquals() {
    const data_type a(0);
    const data_type b(1);
    CheckTrue(a == a, "0 == 0");
    CheckTrue(b == b, "1 == 1");
    CheckFalse(a == b, "0 == 1");
}

template<typename DataT>
void __fastcall TTest_basic_data<DataT>::TestNotEquals() {
    const data_type a(0);
    const data_type b(1);
    CheckFalse(a != a, "0 != 0");
    CheckFalse(b != b, "1 != 1");
    CheckTrue(a != b, "0 != 1");
}

template<>
void __fastcall TTest_basic_data<vm68k::byte>::Test_size() {
    CheckEquals(1U, data_type::size(), "size()");
}

template<>
void __fastcall TTest_basic_data<vm68k::byte>::Test_min() {
    CheckEquals(-0x80, data_type::min(), "min()");
}

template<>
void __fastcall TTest_basic_data<vm68k::byte>::Test_max() {
    CheckEquals(0x7f, data_type::max(), "max()");
}

template<>
void __fastcall TTest_basic_data<vm68k::byte>::Test_umax() {
    CheckEquals(0xff, data_type::umax(), "umax()");
}

template<>
void __fastcall TTest_basic_data<vm68k::word>::Test_size() {
    CheckEquals(2U, data_type::size(), "size()");
}

template<>
void __fastcall TTest_basic_data<vm68k::word>::Test_min() {
    CheckEquals(-0x8000, data_type::min(), "min()");
}

template<>
void __fastcall TTest_basic_data<vm68k::word>::Test_max() {
    CheckEquals(0x7fff, data_type::max(), "max()");
}

template<>
void __fastcall TTest_basic_data<vm68k::word>::Test_umax() {
    CheckEquals(0xffff, data_type::umax(), "umax()");
}

template<>
void __fastcall TTest_basic_data<vm68k::long_word>::Test_size() {
    CheckEquals(4U, data_type::size(), "size()");
}

#pragma option push -w-8041
template<>
void __fastcall TTest_basic_data<vm68k::long_word>::Test_min() {
    CheckEquals(-0x80000000L, data_type::min(), "min()");
}
#pragma option pop

template<>
void __fastcall TTest_basic_data<vm68k::long_word>::Test_max() {
    CheckEquals(0x7fffffffL, data_type::max(), "max()");
}

template<>
void __fastcall TTest_basic_data<vm68k::long_word>::Test_umax() {
    CheckEquals(0xffffffffL, data_type::umax(), "umax()");
}

template class TTest_basic_data<vm68k::byte>;
template class TTest_basic_data<vm68k::word>;
template class TTest_basic_data<vm68k::long_word>;

static void registerTests() {
    Testframework::RegisterTest(TTest_basic_data<vm68k::byte>::Suite());
    Testframework::RegisterTest(TTest_basic_data<vm68k::word>::Suite());
    Testframework::RegisterTest(TTest_basic_data<vm68k::long_word>::Suite());
}
#pragma startup registerTests 33
