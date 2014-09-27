// sqliteppEx1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include "sqlite3pp.h"

using namespace std;

#pragma comment(lib, "sqlitepp.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	sqlite3pp::database db("test.db");
	sqlite3pp::command cmd(db, "INSERT INTO contacts (name, phone) VALUES (?, ?)");
	cmd.binder() << "Mike" << "555-1234";
	int result = cmd.execute();

	sqlite3pp::query qry(db, "SELECT id, name, phone FROM contacts");

	for (int i = 0; i < qry.column_count(); ++i) {
		cout << qry.column_name(i) << "\t";
	}

	cout << endl;

	for (sqlite3pp::query::iterator i = qry.begin(); i != qry.end(); ++i) {
		for (int j = 0; j < qry.column_count(); ++j) {
			cout << (*i).get<char const*>(j) << "\t";
		}
		cout << endl;
	}


	return 0;
}

