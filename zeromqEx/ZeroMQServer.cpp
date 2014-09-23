// ZeroMQServer.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "zmq.hpp"
#include <zmq.hpp>
#include <string>
#include <iostream>
#include <windows.h>

#pragma comment(lib, "libzmq.lib")

int main() {
	//  Prepare our context and socket
	zmq::context_t context(1);
	zmq::socket_t socket(context, ZMQ_REP);
	socket.bind("tcp://*:25251");

	while (true) {
		zmq::message_t request;

		//  Wait for next request from client
		socket.recv(&request);
		std::cout << "Received Hello" << std::endl;

		Sleep(1);

		//  Send reply back to client
		zmq::message_t reply(5);
		memcpy((void *)reply.data(), "World", 5);
		socket.send(reply);
	}
	return 0;
}
