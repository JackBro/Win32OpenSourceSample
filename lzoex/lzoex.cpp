// lzoex.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "lzo/lzoconf.h"
#include "lzo/lzo1x.h"

static const char *progname = NULL;
#define WANT_XMALLOC
#define WANT_LZO_MALLOC
#include "examples/portab.h"

#pragma comment(lib, "lzo2.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	lzo_bytep in;
	lzo_bytep out;
	lzo_voidp wrkmem;
	lzo_uint in_len;
	lzo_uint out_len;
	lzo_uint new_len;

//lzo �ʱ�ȭ
	if (lzo_init() != LZO_E_OK)
	{
		printf("lzo_init() failed\n");
		return 0;
	}

//���� �ε�
	FILE* fp = 0;
	errno_t err = fopen_s(&fp, "LICENSE", "rb");
	if (err != 0)
		return 0;

	fseek(fp, 0L, SEEK_END);
	in_len = ftell(fp);

	fseek(fp, 0L, SEEK_SET);

//�޸� �Ҵ�
//���� �����͸� ������ ��� �������� ũ�Ⱑ ������ ������ ��찡 �ֱ� ������
//����� ����� �����ϴ� ���۴� ���� ���ۺ��� ���� ũ�� ��´�.
	in = (lzo_bytep)xmalloc(in_len);
	out_len = in_len + in_len / 16 + 64 + 3;
	out = (lzo_bytep)xmalloc(out_len);
	wrkmem = (lzo_voidp)xmalloc(LZO1X_1_MEM_COMPRESS);
	if (in == NULL || out == NULL || wrkmem == NULL)
	{
		printf("out of memory\n");
		return 0;
	}

//�����͸� �о� ���δ�.
	fread(in, in_len, 1, fp);
	fclose(fp);

//������ ����
	int r = lzo1x_1_compress(in, in_len, out, &out_len, wrkmem);
	if (r == LZO_E_OK)
		printf("compressed %lu bytes into %lu bytes\n",
		(unsigned long)in_len, (unsigned long)out_len);
	else
	{
		/* this should NEVER happen */
		printf("internal error - compression failed: %d\n", r);
		return 2;
	}
	/* check for an incompressible block */
	if (out_len >= in_len)
	{
		printf("This block contains incompressible data.\n");
		return 0;
	}

//���� ����
	new_len = in_len;
	r = lzo1x_decompress(out, out_len, in, &new_len, NULL);
	if (r == LZO_E_OK && new_len == in_len)
		printf("decompressed %lu bytes back into %lu bytes\n",
		(unsigned long)out_len, (unsigned long)in_len);
	else
	{
		/* this should NEVER happen */
		printf("internal error - decompression failed: %d\n", r);
		return 1;
	}

	lzo_free(wrkmem);
	lzo_free(out);
	lzo_free(in);
	printf("Simple compression test passed.\n");

	return 0;
}

