// msgpackEx.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <msgpack.hpp>
#include <vector>
#include <string>
#include <iostream>

#pragma comment(lib, "msgpack.lib")

int _tmain(int argc, _TCHAR* argv[])
{

//������
	std::vector<std::string> target;
	target.push_back("Hello,");
	target.push_back("World!");

//������ ����ȭ
	msgpack::sbuffer sbuf;  // simple buffer
	msgpack::pack(&sbuf, target);

//����ȭ�� �����͸� ������ȭ
	msgpack::unpacked msg;    
	msgpack::unpack(&msg, sbuf.data(), sbuf.size());
	msgpack::object obj = msg.get();

	std::cout << obj << std::endl;    // ["Hello," "World!"]

//������ȭ�� �����͸� ������ ������ ������ Ÿ������ ��ȯ
	std::vector<std::string> result;
	obj.convert(&result);

	return 0;
}

