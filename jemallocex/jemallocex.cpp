// jemalloc.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "jemalloc/jemalloc.h"

#ifdef _DEBUG
#pragma comment(lib, "jemalloc_debug.lib")
#else
#pragma comment(lib, "jemalloc.lib")
#endif

int _tmain(int argc, _TCHAR* argv[])
{
	je_init();

	void * ptr = je_malloc(2 * 1024 * 1024);

	je_free(ptr);

	je_uninit();

	return 0;
}

