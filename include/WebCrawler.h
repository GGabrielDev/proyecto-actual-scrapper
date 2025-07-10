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
    void crawl(const char* rootUrl, int maxDepth); // pública
    void crawlRecursive(const char* url, TreeNode* parent, int depth, int maxDepth); // interna
    int countLinks() const;
    bool findKeyword(const char* keyword) const;
    void detectBrokenLinks() const;

private:
    NavigationTree* navigationTree;
    LinkedList visitedUrls;
    char* rootUrl;
    char* rootDomain;

    bool isVisited(const char* url);
    void markVisited(const char* url);
};

#endif // WEB_CRAWLER_H
