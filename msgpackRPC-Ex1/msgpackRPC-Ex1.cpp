// msgpackRPC-Ex1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <msgpack/rpc/asio.h>
#include <boost/thread.hpp>

#pragma comment(lib, "msgpack.lib")

int main(int argc, char **argv)
{
	const static int PORT = 8070;

	//Ŭ���̾�Ʈ �񵿱� ����
	boost::asio::io_service client_io;
	msgpack::rpc::asio::client client(client_io);
	client.connect_async(boost::asio::ip::tcp::endpoint(
		boost::asio::ip::address::from_string("127.0.0.1"), PORT));
	boost::thread clinet_thread([&client_io](){ client_io.run(); });

	//RPC ���� ȣ�� add �Լ� ȣ��
	int result1;
	std::cout << "add, 1, 2 = " << client.call_sync(&result1, "add", 1, 2) << std::endl;

	//RPC �񵿱� ȣ�� mul �Լ� ȣ��
	auto request2 = client.call_async("mul", 1.2f, 5.0f);

	//�񵿱� ȣ���̹Ƿ� ���� ����� �������� ����
	std::cout << *request2 << std::endl;

	//����� �� ������ ����� �� ����� ��´�.
	float result2;
	std::cout << "result = " << request2->sync().convert(&result2) << std::endl;

	// ������Ƽ �� ���� �� ��������
	{
		auto request3 = client.call_async("set_number", 64);
		std::cout << *request3 << std::endl;
		request3->sync();
	}
	{
		auto request3 = client.call_async("get_number");
		request3->sync();
		std::cout << *request3 << std::endl;
	}

	getchar();

	//boost asio ����
	client_io.stop();
	clinet_thread.join();

	return 0;
}
