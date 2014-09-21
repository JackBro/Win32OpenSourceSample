// libtomEx4.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <tomcrypt.h>

#pragma comment(lib, "tomcrypt.lib")

bool executeRC4(unsigned char* pBuffer, int nBufferLen)
{
	prng_state prng; //�ǻ� ���� �ѹ� ���ʷ����� 

	int err;
	if ((err = rc4_start(&prng)) != CRYPT_OK) //RC4 �ʱ�ȭ 
		return 0;
	//Ű "Win32OpenSource"�� ���ؼ� ��Ʈ���Ǹ� ������Ŵ 
	if ((err = rc4_add_entropy((const unsigned char*)"Win32OpenSource", 15, &prng)) != CRYPT_OK)
		return 0;

	//RC4 �غ� ����.. PRNG Init 
	if ((err = rc4_ready(&prng)) != CRYPT_OK)
		return 0;

	if (rc4_read(pBuffer, nBufferLen, &prng) != nBufferLen)
		return 0;

	//��ȣȭ ��� pBuffer�� ������ �� 

	rc4_done(&prng);
}


int _tmain(int argc, _TCHAR* argv[])
{

	unsigned char buf[32] = "Hello World";
	int nBufferLen = 11;
	executeRC4(buf, nBufferLen);
	executeRC4(buf, nBufferLen);

	return 0;
}

