// BerkeleyDBEx.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
// BerkeleyDBEx.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "db_cxx.h"
#include <assert.h>

#ifdef _DEBUG
#pragma comment(lib, "libdb61d.lib")
#else
#pragma comment(lib, "libdb61.lib")
#endif

int _tmain(int argc, _TCHAR* argv[])
{
	Db db(NULL, 0); // �����ͺ��̽� ������Ʈ �ʱ�ȭ
	u_int32_t oFlags = DB_CREATE; // �����ͺ��̽��� �������� ������ ������ ��

	//�����ͺ��̽� ����
	try {
		db.open(NULL, //Ʈ����� ������Ʈ�� ���� ������
			"my_db.db", // �����ͺ��̽� ���� �̸�
			NULL,
			DB_BTREE, // �����ͺ��̽��� ��Ʈ���� �����ϴ� ���
			oFlags, // �÷���
			0);
	}
	catch (DbException &e) {
	}
	catch (std::exception &e) {
	}

	float money = 122.45; //Ű
	char *description = "Grocery bill."; //������

	//�����ͺ��̽��� ����
	{

		Dbt key(&money, sizeof(float));
		Dbt data(description, strlen(description) + 1);
		//Ű,������ ���� �����ͺ��̽��� ����� ��. �� Ű�� �����Ѵٸ� ����� �� ��
		int ret = db.put(NULL, &key, &data, DB_NOOVERWRITE);
		if (ret == DB_KEYEXIST) {
			db.err(ret, "Put failed because key %f already exists",
				money);
		}
	}

	//�����ͺ��̽����� �б�
	{
#define DESCRIPTION_SIZE 199
		float money;
		char szDescription[DESCRIPTION_SIZE + 1];
		// Database open omitted for clarity	
		money = 122.45;
		Dbt key, data;
		key.set_data(&money);
		key.set_size(sizeof(float));
		data.set_data(szDescription);
		data.set_ulen(DESCRIPTION_SIZE + 1);
		data.set_flags(DB_DBT_USERMEM);

		//�����ͺ��̽����� Ű ���� 122.45�� ã�Ƽ� �װ��� �����͸� ���´�.
		db.get(NULL, &key, &data, 0);

		//�о�� �����Ͱ��� ���ʿ� �� �����Ͱ��� ��ġ�ؾ� �Ѵ�.
		assert(strcmp(description, szDescription) == 0);
	}

	//�����ͺ��̽��� �ݴ´�.
	try {
		db.close(0);
	}
	catch (DbException &e) {
		
	}
	catch (std::exception &e) {
	}

	return 0;
}

