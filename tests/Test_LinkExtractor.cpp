#include "LinkExtractor.h"
#include "LinkedList.h"
#include "StringUtils.h"
#include "MemoryUtils.h"
#include <cassert>
#include <iostream>

void testExtractLinks() {
    const char* html =
        "<html><body>"
        "<a href=\"http://example.com/page1.html\">Page 1</a>"
        "<a href=\"https://other.com/page2.html\">Page 2</a>"
        "<a href=\"page3.html\">Page 3</a>"
        "</body></html>";

    LinkedList links;
    extractLinks(html, &links);

    assert(links.size() == 3);

    const char* expected[] = {
        "http://example.com/page1.html",
        "https://other.com/page2.html",
        "page3.html"
    };

    for (int i = 0; i < links.size(); ++i) {
        const char* actual = (const char*)links.get(i);
        std::cout << "Link[" << i << "]: \"" << actual << "\"" << std::endl;
        std::cout << "Expected : \"" << expected[i] << "\"" << std::endl;
        assert(compareString(expected[i], actual) == 0);
    }

    std::cout << "[PASSED] testExtractLinks\n";

    // Liberar memoria
    for (int i = 0; i < links.size(); ++i) {
        memFree(links.get(i));
    }
}

int main() {
    testExtractLinks();
    return 0;
}
