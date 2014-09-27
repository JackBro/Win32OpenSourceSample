// libtomEx3.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <tomcrypt.h>

#pragma comment(lib, "tomcrypt.lib")

int md5Test();
int shaTest();


int _tmain(int argc, _TCHAR* argv[])
{
	shaTest();
	//md5Test();

	return 0;
}

int shaTest()
{
	int idx, err;
	hmac_state hmac;
	unsigned char key[20] = "WIN32 OPENSOURCE";
	unsigned char dst[MAXBLOCKSIZE];
	unsigned long dstlen;
	//�ؽ� �˰������� SHA-1 ��� 
	if (register_hash(&sha1_desc) == -1)
	{
		printf("Error registering SHA1\n");
		return -1;
	}

	//Descriptor ���̺��� SHA-1 �ؽ� �˰����� �ε��� ���� 
	idx = find_hash("sha1");
	dstlen = sizeof(dst);
	//SHA-1 �˰���� Ű "WIN32 OPENSOURCE"�� �̿��Ͽ� "hello"��� �������� �ؽ� ������� dst�� ���� 
	err = hmac_memory(idx, key, 4, (const unsigned char*)"hello", 5, dst, &dstlen);

	return err;
}

int  md5Test()
{
	hash_state md;
	char *in = "hello world";
	unsigned char out[16];
	/* setup the hash */
	md5_init(&md);
	/* add the message */
	md5_process(&md, (const unsigned char *)in, strlen((const char*)in));
	/* get the hash in out[0..15] */
	md5_done(&md, out);

	return 0;
}
