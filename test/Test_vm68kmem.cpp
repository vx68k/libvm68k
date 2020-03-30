/*
 * Test_vm68kmem - Test cases for libvm68k (implementation)
 * Copyright (C) 2012 Kaz Nishimura
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

#include "Test_vm68kmem.h"

#include <vm68k>
#include <TestFramework.hpp>

using namespace vm68k;

class TTest_memory_map : public TTestCase {
private:
    memory_map *obj;

public:
    __fastcall virtual TTest_memory_map(System::String name) : TTestCase(name) {
    }
    virtual void __fastcall SetUp();
    virtual void __fastcall TearDown();

__published:
};

void __fastcall TTest_memory_map::SetUp() {
    obj = new memory_map();
}

void __fastcall TTest_memory_map::TearDown() {
    delete obj;
}

static void registerTests() {
    Testframework::RegisterTest(TTest_memory_map::Suite());
}
#pragma startup registerTests 33
