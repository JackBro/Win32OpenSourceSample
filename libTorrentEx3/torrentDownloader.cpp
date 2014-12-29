// torrentDownloader.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <stdlib.h>
#include "libtorrent/entry.hpp"
#include "libtorrent/bencode.hpp"
#include "libtorrent/session.hpp"

#pragma comment(lib, "torrent-rasterbar.lib")
#pragma comment(lib, "DbgHelp.lib")


int main(int argc, char* argv[])
{
	using namespace libtorrent;

	//�Ķ���ͷ� �䷻Ʈ ������ �Է��Ѵ�.
	if (argc != 2)
	{
		fputs("usage: ./simple_client torrent-file\n"
			"to stop the client, press return.\n", stderr);
		return 1;
	}

	session s;
	error_code ec;
	s.listen_on(std::make_pair(6881, 6889), ec);
	if (ec)
	{
		fprintf(stderr, "failed to open listen socket: %s\n", ec.message().c_str());
		return 1;
	}

	//�������� ����� ������ �����Ѵ�.
	add_torrent_params p;
	p.save_path = "./";
	p.ti = new torrent_info(argv[1], ec);
	if (ec)
	{
		fprintf(stderr, "%s\n", ec.message().c_str());
		return 1;
	}


	//�䷻Ʈ ������ �߰��ؼ� ��׶���� ���� �ٿ�ε带 �����Ѵ�.
	s.add_torrent(p, ec);
	if (ec)
	{
		fprintf(stderr, "%s\n", ec.message().c_str());
		return 1;
	}

	char a;
	scanf("%c\n", &a);
	return 0;
}