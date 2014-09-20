// zpackEx2.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "zpack.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include <assert.h>

#ifdef _DEBUG
#pragma comment(lib, "zpackd.lib")
#else
#pragma comment(lib, "zpack.lib")
#endif

int _tmain(int argc, _TCHAR* argv[])
{
	bool result = ZpackAdd( L"test.7z", L"ReadMe.txt", 5, L"123" );
	assert(result == true);

	const TCHAR* szInfo = ZpackFolderInfo( L"test.7z", L"ReadMe.txt", L"123" );
	assert(szInfo != NULL);

	result = ZpackExtract(L"test.7z", L"", L"", true, L"123");
	assert(result == true);

	return 0;
}

