#include <System.hpp>
#pragma hdrstop

#include "Test_vm68kdata.h"

#include <bits/vm68kdata.h>
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
    using vm68k:: byte;
    CheckEquals(1U, byte::size(), "byte::size()");
    CheckEquals(-0x80, byte::min(), "byte::min()");
    CheckEquals(0x7f, byte::max(), "byte::max()");
    CheckEquals(0xff, byte::umax(), "byte::umax()");
}

void __fastcall TTest_byte::TestBasic()
{
    using vm68k:: byte;
    CheckEquals(0, byte(0), "byte(0)");
    CheckEquals(0x7f, byte(0x7f), "byte(0x7f)");
    CheckEquals(-0x80, byte(0x7f + 1), "byte(0x7f + 1)");
    CheckEquals(-0x80, byte(-0x80), "byte(-0x80)");
    CheckEquals(0x7f, byte(-0x80 - 1), "byte(-0x80 - 1)");
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
    CheckEquals(0, word(0), "word(0)");
    CheckEquals(0x7fff, word(0x7fff), "word(0x7fff)");
    CheckEquals(-0x8000, word(0x7fff + 1), "word(0x7fff + 1)");
    CheckEquals(-0x8000, word(-0x8000), "word(-0x8000)");
    CheckEquals(0x7fff, word(-0x8000 - 1), "word(-0x8000 - 1)");
}

void __fastcall TTest_long_word::SetUp()
{
}

void __fastcall TTest_long_word::TearDown()
{
}

void __fastcall TTest_long_word::TestStatic()
{
    CheckEquals(4U, long_word::size(), "long_word::size()");
    CheckEquals(-0x7fffffffL - 1, long_word::min(), "long_word::min()");
    CheckEquals(0x7fffffffL, long_word::max(), "long_word::max()");
    CheckEquals(0xffffffffU, long_word::umax(), "long_word::umax()");
}

void __fastcall TTest_long_word::TestBasic()
{
    CheckEquals(0, long_word(0), "long_word(0)");
    CheckEquals(0x7fffffffL, long_word(0x7fffffffL), "long_word(0x7fffffffL)");
    CheckEquals(-0x7fffffffL - 1, long_word(0x7fffffffL + 1), "long_word(0x7fffffffL + 1)");
    CheckEquals(-0x7fffffffL - 1, long_word(-0x7fffffffL - 1), "long_word(-0x80000000L)");
    CheckEquals(0x7fffffffL, long_word(-0x7fffffffL - 2), "long_word(-0x80000000L - 1)");
}

static void registerTests()
{
    Testframework::RegisterTest(TTest_byte::Suite());
    Testframework::RegisterTest(TTest_word::Suite());
    Testframework::RegisterTest(TTest_long_word::Suite());
}
#pragma startup registerTests 33
