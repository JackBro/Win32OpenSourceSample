// breakpadEx.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "BreakPad.h"

#pragma comment(lib, "exception_handler.lib")

void GenerateBug()
{
	int* pNull = 0;
	*pNull = 5;
}

int _tmain(int argc, _TCHAR* argv[])
{
	BreakPad handler;
	handler.Install();

	GenerateBug();

	return 0;
}

