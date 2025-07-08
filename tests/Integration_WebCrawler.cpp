#include "WebCrawler.h"
#include "StringUtils.h"
#include <iostream>
#include <cassert>

void testCrawlWikipedia() {
    const char* startUrl = "https://en.wikipedia.org/wiki/Web_crawler";

    WebCrawler crawler;
    crawler.crawl(startUrl, 1); // Profundidad 1

    int count = crawler.countLinks();
    std::cout << "[INFO] Total links found: " << count << std::endl;

    assert(count > 0); // Esperamos al menos algunos enlaces

    std::cout << "[PASSED] testCrawlWikipedia\n";
}

int main() {
    testCrawlWikipedia();
    return 0;
}
