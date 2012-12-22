#include <System.hpp>
#pragma hdrstop

#include "Test_vm68kdata.h"

#include <vm68k>
#include <TestFramework.hpp>

using namespace vm68k;

class TTest_byte : public TTestCase
{
public:
    __fastcall virtual TTest_byte(System::String name)
        : TTestCase(name)
    {
    }
    virtual void __fastcall SetUp();
    virtual void __fastcall TearDown();

__published:
    void __fastcall TestStatic();
    void __fastcall TestBasic();
};

class TTest_word : public TTestCase
{
public:
    __fastcall virtual TTest_word(System::String name)
        : TTestCase(name)
    {
    }
    virtual void __fastcall SetUp();
    virtual void __fastcall TearDown();

__published:
    void __fastcall TestStatic();
    void __fastcall TestBasic();
};

class TTest_long_word : public TTestCase
{

public:
    __fastcall virtual TTest_long_word(System::String name)
        : TTestCase(name)
    {
    }
    virtual void __fastcall SetUp();
    virtual void __fastcall TearDown();

__published:
    void __fastcall TestStatic();
    void __fastcall TestBasic();
};

void __fastcall TTest_byte::SetUp()
{
}

void __fastcall TTest_byte::TearDown()
{
}

void __fastcall TTest_byte::TestStatic()
{
    CheckEquals(1U, byte::size(), "byte::size()");
    CheckEquals(-0x80, byte::min(), "byte::min()");
    CheckEquals(0x7f, byte::max(), "byte::max()");
    CheckEquals(0xff, byte::umax(), "byte::umax()");
}

void __fastcall TTest_byte::TestBasic()
{
    using vm68k::byte;
    byte zero1;
    byte zero2(0);
    byte max1(0x7f);
    byte min1(-0x80);
    byte omax1(max1 + 1);
    byte omin1(min1 - 1);
    CheckEquals(0, zero1, "byte()");
    CheckEquals(0, zero2, "byte(0)");
    CheckEquals(0x7f, max1, "byte(0x7f)");
    CheckEquals(-0x80, min1, "byte(-0x80)");
    CheckEquals(-0x80, omax1, "byte(byte(0x7f) + 1)");
    CheckEquals(0x7f, omin1, "byte(byte(-0x80) - 1)");
    CheckTrue(zero1 == zero2, "byte() == byte(0)");
    CheckFalse(zero1 != zero2, "byte() != byte(0)");
}

void __fastcall TTest_word::SetUp()
{
}

void __fastcall TTest_word::TearDown()
{
}

void __fastcall TTest_word::TestStatic()
{
    CheckEquals(2U, word::size(), "word::size()");
    CheckEquals(-0x8000, word::min(), "word::min()");
    CheckEquals(0x7fff, word::max(), "word::max()");
    CheckEquals(0xffff, word::umax(), "word::umax()");
}

void __fastcall TTest_word::TestBasic()
{
    word zero1;
    word zero2(0);
    word max1(0x7fff);
    word min1(-0x8000);
    word omax1(max1 + 1);
    word omin1(min1 - 1);
    CheckEquals(0, zero1, "word()");
    CheckEquals(0, zero2, "word(0)");
    CheckEquals(0x7fff, max1, "word(0x7fff)");
    CheckEquals(-0x8000, min1, "word(-0x8000)");
    CheckEquals(-0x8000, omax1, "word(word(0x7fff) + 1)");
    CheckEquals(0x7fff, omin1, "word(word(-0x8000) - 1)");
    CheckTrue(zero1 == zero2, "word() == word(0)");
    CheckFalse(zero1 != zero2, "word() != word(0)");
}

void __fastcall TTest_long_word::SetUp()
{
}

void __fastcall TTest_long_word::TearDown()
{
}

void __fastcall TTest_long_word::TestStatic()
{
#pragma option push -w-8041
    CheckEquals(4U, long_word::size(), "long_word::size()");
    CheckEquals(-0x80000000L, long_word::min(), "long_word::min()");
    CheckEquals(0x7fffffffL, long_word::max(), "long_word::max()");
    CheckEquals(0xffffffffU, long_word::umax(), "long_word::umax()");
#pragma option pop
}

void __fastcall TTest_long_word::TestBasic()
{
#pragma option push -w-8041
    long_word zero1;
    long_word zero2(0);
    long_word max1(0x7fffffffL);
    long_word min1(-0x80000000L);
    long_word omax1(max1 + 1);
    long_word omin1(min1 - 1);
    CheckEquals(0, zero1, "long_word()");
    CheckEquals(0, zero2, "long_word(0)");
    CheckEquals(0x7fffffffL, max1, "long_word(0x7fffffff)");
    CheckEquals(-0x80000000L, min1, "long_word(-0x80000000)");
    CheckEquals(-0x80000000L, omax1, "long_word(long_word(0x7fffffff) + 1)");
    CheckEquals(0x7fffffffL, omin1, "long_word(long_word(-0x80000000) - 1)");
    CheckTrue(zero1 == zero2, "long_word() == long_word(0)");
    CheckFalse(zero1 != zero2, "long_word() != long_word(0)");
#pragma option pop
}

static void registerTests()
{
    Testframework::RegisterTest(TTest_byte::Suite());
    Testframework::RegisterTest(TTest_word::Suite());
    Testframework::RegisterTest(TTest_long_word::Suite());
}
#pragma startup registerTests 33
