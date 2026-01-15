#include <iostream>
#include <curl/curl.h>


size_t write_call_back(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main()
{

    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl_easy_init(curl);
    std::string url = "https://httpbin.org/ip";
    std::string proxyServer = "http://proxyserver:8080";
    

    if (curl) {
	curl_easy_setopt(curl, CURLOPT_URL, url);
	curl_easy_setopt(curl, CURLOPT_PROXY, proxyServer);
	curl_easy_setopt(curl, CURL_PROXYUSERPWD, "username:password");
	curl_easy_setopt(curl, CURL_WRITEFUNCTION, write_call_back);
	curl_easy_setopt(curl, CURL_WRITEDATA, &readBuffer);


	res = curl_easy_perform(curl);

	if (res != CURLE_OK) {
	    std::cerr << "curl_easy_perform(): failed: " << curl_easy_strerror(res) << std::endl;

	} else {
	    std::cout << "Response: " << readBuffer << std::endl;

	}

	curl_easy_cleanup(curl);
	
	


    }
    curl_global_cleanup();

    return 0;

}

