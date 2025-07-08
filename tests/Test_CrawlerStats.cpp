#include "WebCrawler.h"
#include <iostream>
#include <cassert>

void testCrawlerStats() {
    WebCrawler crawler;
    crawler.crawl("https://en.wikipedia.org/wiki/Web_crawler", 1);

    int total = crawler.countLinks();
    assert(total > 0);

    std::cout << "[PASSED] testCrawlerStats\n";
}

int main() {
    testCrawlerStats();
    return 0;
}
