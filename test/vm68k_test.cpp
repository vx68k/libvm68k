//---------------------------------------------------------------------------
// DUnit Project File.
//   Entry point of C++ project using DUnit framework.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <tchar.h>
#include <GUITestRunner.hpp>


WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
  try
  {
     Application->Initialize();
     Guitestrunner::RunRegisteredTests();
  }
  catch (Exception &exception)
  {
     Application->ShowException(&exception);
  }
  catch (...)
  {
     try
     {
       throw Exception("");
     }
     catch (Exception &exception)
     {
       Application->ShowException(&exception);
     }
  }
  return 0;
}

