#include "MemoryUtils.h"
#include "WebFetcher.h"
#include <curl/curl.h>

struct MemoryBuffer {
    char* data;
    size_t size;
};

static size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t totalSize = size * nmemb;
    MemoryBuffer* mem = (MemoryBuffer*)userp;

    char* ptr = (char*)memRealloc(mem->data, mem->size + totalSize + 1);
    if (ptr == nullptr) {
        return 0; // out of memory
    }

    mem->data = ptr;
    memCopy(&(mem->data[mem->size]), contents, totalSize);
    mem->size += totalSize;
    mem->data[mem->size] = '\0';

    return totalSize;
}

char* fetchPage(const char* url) {
    CURL* curl;
    CURLcode res;

    MemoryBuffer buffer;
    buffer.data = (char*)memAlloc(1);
    buffer.size = 0;

    curl = curl_easy_init();
    if (!curl) return nullptr;

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&buffer);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        memFree(buffer.data);
        buffer.data = nullptr;
    }

    curl_easy_cleanup(curl);
    return buffer.data; // ¡No olvides liberar esto luego!
}
