// helloworld.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <hashlibpp.h>

#pragma comment(lib, "hashlib2.lib")

int main(int argc, char **argv, char **env)
{
	hashwrapper *h = new md5wrapper();
	h->test();
	std::string md5 = h->getHashFromString("hello world");
	std::cout << md5 << std::endl;
	delete h;
	return 0;
}
