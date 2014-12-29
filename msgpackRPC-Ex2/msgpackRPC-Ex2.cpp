// msgpackRPC-Ex2.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <msgpack/rpc/asio.h>
#include <boost/thread.hpp>

#pragma comment(lib, "msgpack.lib")

class SomeClass
{
	int m_number;

public:
	void setNumber(const int &number){ m_number = number; }
	int getNumber()const{ return m_number; }
};


int main(int argc, char **argv)
{
	const static int PORT = 8070;

	//����ó�� Ŭ���̾�Ʈ ��û�� ó���ϱ� ���� �ڵ鷯 ���(add, mul)
	//�����Լ��� ����
	msgpack::rpc::asio::dispatcher dispatcher;
	dispatcher.add_handler("add", [](int a, int b)->int{ return a + b; });
	dispatcher.add_handler("mul", [](float a, float b)->float{ return a*b; });
	SomeClass s;
	//������Ƽ�� ���. add_property�� ���ؼ� SomeClass �ν��Ͻ��� ����ϰ� ���� �޼ҵ� getNumber, setNumber �޼ҵ带 ����Ѵ�.
	dispatcher.add_property("number", std::function<SomeClass*()>([&s](){ return &s; })
		, &SomeClass::getNumber
		, &SomeClass::setNumber
		);

	//boost asio ���� ����
	//���� ������ ��û�ؿ��� ��� �����ķ� �ش� ������ ó���Ѵ�.
	boost::asio::io_service server_io;
	msgpack::rpc::asio::server server(server_io, [&dispatcher](
		const msgpack::object &msg,
		std::shared_ptr<msgpack::rpc::asio::session> session)
	{
		dispatcher.dispatch(msg, session);
	});

	//������ ��Ʈ 8070�� �����ϰ� ���񽺸� �����Ѵ�.
	server.listen(boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), PORT));
	boost::thread server_thread([&server_io](){ server_io.run(); });

	getchar();

	server_io.stop();
	server_thread.join();

	return 0;
}


