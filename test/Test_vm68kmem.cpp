#include <System.hpp>
#pragma hdrstop

#include "Test_vm68kmem.h"

#include <vm68kmem.h>
#include <TestFramework.hpp>

class TTest_memory_map : public TTestCase
{
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
}

void __fastcall TTest_memory_map::TearDown()
{
}

static void registerTests()
{
    Testframework::RegisterTest(TTest_memory_map::Suite());
}
#pragma startup registerTests 33
