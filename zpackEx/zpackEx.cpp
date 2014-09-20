// zpackEx.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "zpack.h"
#include <string>
#include <iostream>
#include <Windows.h>

#ifdef _DEBUG
#pragma comment(lib, "zpackd.lib")
#else
#pragma comment(lib, "zpack.lib")
#endif

int _tmain(int argc, _TCHAR* argv[])
{
	int start = GetTickCount();

	unsigned char buf[1024] = { 0, };
	size_t destSize = sizeof(buf);

	unsigned char buf2[1024] = { 0, };
	size_t destSize2 = sizeof(buf2);


	std::string testData = "���ع��� ��λ��� ������ �⵵�� �ϴ����� �����ϻ� �츮���� ���� ����ȭ ��õ�� ȭ������ ���ѻ�� �������� ���� �����ϼ� �������� �� �ҳ��� ö���� �θ��� �ٶ����� �Һ����� �츮 ����ϼ� ����ȭ ��õ�� ȭ������ ���ѻ�� �������� ���� �����ϼ�";

	for (int i = 0; i < 100; ++i)
	{
	
		CompressLZMA((unsigned char const *)testData.c_str(), testData.size(), buf, destSize);
		UnCompressLZMA(buf, destSize, buf2, destSize2);
	}

	std::cout << (GetTickCount() - start) * 0.001f << std::endl;

	return 0;
}

