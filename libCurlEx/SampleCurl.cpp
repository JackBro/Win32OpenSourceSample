// SampleCurl.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include<iostream>

extern "C" {
#include<curl/curl.h>
}

#ifdef _DEBUG
#pragma comment(lib, "libcurld.lib")
#else
#pragma comment(lib, "libcurl.lib")
#endif

int main(const int argc, const char** argv){

	if (argc != 2){
		std::cerr << " Usage: ./" << argv[0] << " {url} [debug]" << std::endl;
		return 0;
	}

	const char* url = argv[1];

	// lubcURL �ʱ�ȭ 
	curl_global_init(CURL_GLOBAL_ALL);

	// context��ü�� ����
	CURL* ctx = curl_easy_init();

	if (NULL == ctx){
		std::cerr << "Unable to initialize cURL interface" << std::endl;
		return 0;
	}

	// context ��ü�� �����Ѵ�.	
	// �ܾ�� url�� ����ϰ�, url�� URL�������� �˷��ش�.
	curl_easy_setopt(ctx, CURLOPT_URL, url);

	// no progress bar:
	curl_easy_setopt(ctx, CURLOPT_NOPROGRESS, 1);

	// ����� ǥ�ؿ����� ����ϵ��� �ϴ�. 
	curl_easy_setopt(ctx, CURLOPT_WRITEHEADER, stderr);


	// body �����ʹ� ǥ����� �ϵ��� �Ѵ�.
	curl_easy_setopt(ctx, CURLOPT_WRITEDATA, stdout);

	// context ��ü�� ���� ���� 


	// ���������� �ܾ�´�. 

	const CURLcode rc = curl_easy_perform(ctx);

	if (CURLE_OK != rc){

		std::cerr << "Error from cURL: " << curl_easy_strerror(rc) << std::endl;
	}
	else{

		// get some info about the xfer:
		double statDouble;
		long statLong;
		char* statString = NULL;

		// HTTP �����ڵ带 ���´�. 
		if (CURLE_OK == curl_easy_getinfo(ctx, CURLINFO_HTTP_CODE, &statLong)){
			std::cout << "Response code:  " << statLong << std::endl;
		}

		// Content-Type �� ���´�.
		if (CURLE_OK == curl_easy_getinfo(ctx, CURLINFO_CONTENT_TYPE, &statString)){
			std::cout << "Content type:   " << statString << std::endl;
		}

		// �ٿ�ε��� ������ ũ�⸦ ���´�.
		if (CURLE_OK == curl_easy_getinfo(ctx, CURLINFO_SIZE_DOWNLOAD, &statDouble)){
			std::cout << "Download size:  " << statDouble << "bytes" << std::endl;
		}

		// 
		if (CURLE_OK == curl_easy_getinfo(ctx, CURLINFO_SPEED_DOWNLOAD, &statDouble)){
			std::cout << "Download speed: " << statDouble << "bytes/sec" << std::endl;
		}

	}

	// cleanup
	curl_easy_cleanup(ctx);
	curl_global_cleanup();

	return(0);

}