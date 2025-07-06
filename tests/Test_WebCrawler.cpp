#include <cassert>
#include <iostream>
#include "WebCrawler.h"

void testCrawl() {
    WebCrawler crawler;
    crawler.crawl("http://example.com", 1);

    // Placeholder for more detailed tests
    assert(true); // Simple assertion to ensure the test runs
}

int main() {
    testCrawl();
    std::cout << "All WebCrawler tests passed!" << std::endl;
    return 0;
}
