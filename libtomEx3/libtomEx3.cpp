// libtomEx3.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <tomcrypt.h>

#pragma comment(lib, "tomcrypt.lib")


int _tmain(int argc, _TCHAR* argv[])
{
	int idx, err;
	hmac_state hmac;
	unsigned char key[16] = "CGSF";
	unsigned char dst[MAXBLOCKSIZE];
	unsigned long dstlen;
	//�ؽ� �˰������� SHA-1 ��� 
	if (register_hash(&sha1_desc) == -1)
	{
		printf("Error registering SHA1\n");
		return -1;

		//Descriptor ���̺��� SHA-1 �ؽ� �˰����� �ε��� ���� 
		idx = find_hash("sha1");
		dstlen = sizeof(dst);
		//SHA-1 �˰���� Ű "CGSF"�� �̿��Ͽ� "hello"��� �������� �ؽ� ������� dst�� ���� 
		err = hmac_memory(idx, key, 4, (const unsigned char*)"hello", 5, dst, &dstlen);
	}

	return 0;
}

