// BassTest.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "BassSoundManager.h"

#pragma comment(lib, "bass.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	CBassSoundManager* pBass = new CBassSoundManager();
	pBass->Initialize();
	pBass->FileLoad("5.mp3");
	pBass->Play(true);

	getchar();

	pBass->Delete();
	delete pBass;

	return 0;
}

