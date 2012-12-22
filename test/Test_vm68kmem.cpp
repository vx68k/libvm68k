#include <System.hpp>
#pragma hdrstop

#include "Test_vm68kmem.h"

#include <vm68k>
#include <TestFramework.hpp>

using namespace vm68k;

class TTest_memory_map : public TTestCase
{
private:
    memory_map *obj;

public:
    __fastcall virtual TTest_memory_map(System::String name)
        : TTestCase(name)
    {
    }
    virtual void __fastcall SetUp();
    virtual void __fastcall TearDown();

__published:
};

void __fastcall TTest_memory_map::SetUp()
{
    obj = new memory_map();
}

void __fastcall TTest_memory_map::TearDown()
{
    delete obj;
}

static void registerTests()
{
    Testframework::RegisterTest(TTest_memory_map::Suite());
}
#pragma startup registerTests 33
