#ifndef WEB_CRAWLER_H
#define WEB_CRAWLER_H

#include "NavigationTree.h"
#include "LinkedList.h"
#include "StringUtils.h"

class WebCrawler {
public:
    WebCrawler();
    ~WebCrawler();

/// Explora recursivamente los enlaces desde rootUrl hasta maxDepth
void crawl(const char* rootUrl, int maxDepth);
    int countLinks() const;
    bool findKeyword(const char* keyword) const;
    void detectBrokenLinks() const;

private:
    NavigationTree* navigationTree;
    LinkedList visitedUrls;

    bool isVisited(const char* url) const;
    void markVisited(const char* url);
};

#endif // WEB_CRAWLER_H
