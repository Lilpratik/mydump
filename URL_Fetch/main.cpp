#include <curl/curl.h>
#include <iostream>

// CURLU *h = curl_url();
// void parsingURL(char *url) {
//     rc = curl_url_dup(h, CURLUPART_URL, &url, 0);
    
// }
static size_t WriteCallback(char* ptr, size_t size, size_t nmemb, void* userdata) {

    ((std::string*)userdata)->append((char*)ptr, size * nmemb);
    return size * nmemb;
}


int main() {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://httpbin.org/get");
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


		       
