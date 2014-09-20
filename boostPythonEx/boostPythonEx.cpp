// boostPythonEx.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <boost/python.hpp>  

using namespace boost::python;

int main(int args, char** argv)
{
	Py_Initialize();

	try
	{
		object main = import("__main__");
		object space = main.attr("__dict__");

		PySys_SetArgv(args, argv);
		object ignored = exec_file("gmail.py", space);
	}
	catch (error_already_set const&)
	{
		PyErr_Print();
	}


	Py_Finalize();
}