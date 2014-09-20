// libzipEx.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "zip.h"

#pragma comment(lib, "zip.lib")

int main()
{
	//����� ���� ����
	int err = 0;
	zip *z = zip_open("foo.zip", 0, &err);

	//���� ���ϳ��� �־��� ������ �����ϴ��� Ȯ��
	//���� �̸��� ��ҹ��ڸ� ��Ȯ�� �־��־�� �Ѵ�.
	const char *name = "ReadMe.txt";
	struct zip_stat st;
	zip_stat_init(&st);
	zip_stat(z, name, 0, &st);

	//ã���� �ϴ� ������ ũ�� ��ŭ �޸� �Ҵ�
	char *contents = new char[st.size];

	//ã���� �ϴ� ������ �����͸� �� ������ ������ �޸𸮿� ī��
	zip_file *f = zip_fopen(z, "ReadMe.txt", 0);
	zip_fread(f, contents, st.size);
	zip_fclose(f);

	//���̺귯���� �����Ѵ�.
	zip_close(z);
}