#include <bits/stdc++.h>
#include <curl/curl.h>


static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userdata)
{
    ((std::string*)userdata)->append((char*)contents, size * nmemb);
    return size * nmemb;
}


int main() {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://httpbin.org/cookies/set?name=value");
        curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            std::cout << "Response: " << readBuffer << std::endl;
        }        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    
    return 0;
}	
	
