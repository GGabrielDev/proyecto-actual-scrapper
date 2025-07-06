#include <iostream>
#include <cassert>
#include "WebFetcher.h"
#include "StringUtils.h"

void testFetchPage() {
    const char* url = "http://example.com";
    char* page = fetchPage(url);
    assert(page != nullptr);

    int len = stringLength(page);
    std::cout << "[INFO] Page fetched (" << len << " bytes)" << std::endl;

    const char* marker = "<h1>Example Domain</h1>";
    bool found = false;

    for (int i = 0; page[i] != '\0'; ++i) {
        int j = 0;
        while (marker[j] != '\0' && page[i + j] != '\0' && marker[j] == page[i + j]) {
            ++j;
        }
        if (marker[j] == '\0') {
            found = true;
            break;
        }
    }

    assert(found);
    std::cout << "[PASSED] testFetchPage" << std::endl;

    free(page);
}

int main() {
    testFetchPage();
    return 0;
}
