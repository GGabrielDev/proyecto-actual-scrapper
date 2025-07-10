#include "WebCrawler.h"
#include "StringUtils.h"
#include <iostream>
#include <cassert>

void testCrawlWikipediaDepthComparison() {
    const char* startUrl = "https://docs.redhat.com/en";

    WebCrawler crawler1;
    crawler1.crawl(startUrl, 1);
    int count1 = crawler1.countLinks();

    WebCrawler crawler2;
    crawler2.crawl(startUrl, 2);
    int count2 = crawler2.countLinks();

    std::cout << "[DEBUG] count1 = " << count1 << ", count2 = " << count2 << std::endl;

    // No garantizamos que count2 > count1 si los enlaces se repiten o son equivalentes.
    // Verificamos que no sea menor, y que ambos tengan al menos algo.
    assert(count1 > 0);
    assert(count2 >= count1);

    std::cout << "[PASSED] testCrawlWikipediaDepthComparison\n";
}

int main() {
    testCrawlWikipediaDepthComparison();
    return 0;
}
