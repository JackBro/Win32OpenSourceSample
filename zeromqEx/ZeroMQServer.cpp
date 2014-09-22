// ZeroMQServer.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "zmq.hpp"

#pragma comment(lib, "libzmq.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	zmq::context_t context(1);

	//  Socket facing clients
	zmq::socket_t frontend(context, ZMQ_ROUTER);
	frontend.bind("tcp://*:5559");

	//  Socket facing services
	zmq::socket_t backend(context, ZMQ_DEALER);
	zmq_bind(backend, "tcp://*:5560");

	//  Start built-in device
	zmq_device(ZMQ_QUEUE, frontend, backend);

	return 0;
}

