/*
 * Win32-specific code.
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

#if HAVE_CONFIG_H
#include <config.h>
#endif
#if __BORLANDC__
#pragma hdrstop
#endif

#include <windows.h>
//---------------------------------------------------------------------------
//   DLL でランタイム ライブラリの静的バージョンを使用する場合の
//   DLL メモリ管理に関する重要なメモ:
//
//   パラメータまたは関数結果として String オブジェクト (またはネストした
//   String が含まれている構造体やクラス) を渡す関数を DLL でエクスポートする場合は、
//   DLL プロジェクトにもその DLL を使用する他のあらゆるプロジェクトにもライブラリ
//   MEMMGR.LIB を追加する必要があります。また、その DLL を使用する他のプロジェクトで、
//   DLL からエクスポートされる TObject 派生でない任意のクラスに対する
//   new 演算または delete 演算を実行する場合も、MEMMGR.LIB を使用する必要が
//   あります。プロジェクトに MEMMGR.LIB を追加すると、DLL とその呼び出し元の EXE が
//   メモリ マネージャとして BORLNDMM.DLL を使用するようになります。これらの場合、
//   BORLNDMM.DLL ファイルを作成対象の DLL と一緒に配置しなければなりません。
//
//   BORLNDMM.DLL を使用しないようにするには、"char *" 型または ShortString 型の
//   パラメータを使って文字列情報を渡します。
//
//   DLL で RTL の動的バージョンを使用する場合、MEMMGR.LIB は暗黙的に
//   追加されるため、明示的に追加する必要はありません。
//---------------------------------------------------------------------------

#pragma argsused
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fwdreason, LPVOID lpvReserved)
{
	return 1;
}
//---------------------------------------------------------------------------
