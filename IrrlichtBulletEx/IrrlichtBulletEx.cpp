// IrrlichtBulletEx.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "irrBulletBox.h"

#ifdef _DEBUG
#pragma comment(lib, "LinearMath_vs2010_debug.lib")
#pragma comment(lib, "BulletDynamics_vs2010_debug.lib")
#pragma comment(lib, "BulletCollision_vs2010_debug.lib")
#else
#pragma comment(lib, "LinearMath_vs2010.lib")
#pragma comment(lib, "BulletDynamics_vs2010.lib")
#pragma comment(lib, "BulletCollision_vs2010.lib")
#endif

#pragma comment(lib, "Irrlicht.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	irrBulletBox app;
	app.Init(argv[0]);

	app.Run();
	

	return 0;
}

