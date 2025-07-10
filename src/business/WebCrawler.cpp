#include "LinkExtractor.h"
#include "MemoryUtils.h"
#include "WebCrawler.h"
#include "WebFetcher.h"
#include "StringUtils.h"
#include <iostream>

WebCrawler::WebCrawler()
    : navigationTree(new NavigationTree()), rootUrl(nullptr), rootDomain(nullptr) {}

WebCrawler::~WebCrawler() {
    delete navigationTree;
    if (rootUrl) memFree(rootUrl);
    if (rootDomain) memFree(rootDomain);
}

void WebCrawler::crawl(const char* rootUrl, int maxDepth) {
    std::cout << "[DEBUG] Iniciando crawl raíz: " << rootUrl << " hasta profundidad: " << maxDepth << std::endl;

    if (rootUrl == nullptr || maxDepth < 0) return;

    int len = stringLength(rootUrl) + 1;
    this->rootUrl = (char*)memAlloc(len);
    copyString(this->rootUrl, rootUrl, len);

    this->rootDomain = extractDomain(rootUrl);

    crawlRecursive(rootUrl, nullptr, 0, maxDepth);
}

void WebCrawler::crawlRecursive(const char* url, TreeNode* parent, int depth, int maxDepth) {
    std::cout << "[DEBUG] Entrando a: " << url << " con profundidad: " << depth << std::endl;

    if (depth > maxDepth) return;

    if (isVisited(url)) return;
    markVisited(url);

    navigationTree->addNode(url, parent);

    char* html = fetchPage(url);
    if (!html) return;

    LinkedList links;
    extractLinks(html, &links);

    TreeNode* current = navigationTree->findNode(url);
    if (!current) {
        std::cout << "[ERROR] No se encontró nodo para: " << url << std::endl;
        memFree(html);
        return;
    }

    for (int i = 0; i < links.size(); ++i) {
        char* childUrl = static_cast<char*>(links.get(i));

        if (stringLength(childUrl) == 0 || childUrl[0] == '#') {
            memFree(childUrl);
            continue;
        }

        std::cout << "[DEBUG] URL original: " << childUrl << std::endl;
        char* norm = normalizeUrl(this->rootUrl, childUrl);
        std::cout << "[DEBUG] URL normalizada: " << norm << std::endl;

        bool isInternal = false;
        int domainLen = stringLength(rootDomain);
        int normLen = stringLength(norm);

        isInternal = startsWith(norm, rootDomain);

        // std::cout << "[DEBUG] Agregando nodo: " << norm
        //           << " hijo de: " << (current ? current->url : "ROOT")
        //           << " a profundidad: " << (depth + 1)
        //           << std::endl;
        navigationTree->addNode(norm, current);  // Importante: usar URL normalizada

        if (isInternal) {
            crawlRecursive(norm, current, depth + 1, maxDepth);
        }

        memFree(norm);
        memFree(childUrl);
    }

    memFree(html);
}

int WebCrawler::countLinks() const {
    LinkStats stats = navigationTree->computeStats(rootDomain);  // Cambiado a rootDomain
    std::cout << "[INFO] Total: " << stats.total
              << ", Internos: " << stats.internal
              << ", Externos: " << stats.external
              << ", Profundidad: " << stats.maxDepth
              << std::endl;
    return stats.total;
}

bool WebCrawler::findKeyword(const char* keyword) const {
    return false;
}

void WebCrawler::detectBrokenLinks() const {
    // Placeholder
}

bool WebCrawler::isVisited(const char* url) {
    char* norm = normalizeUrl(this->rootUrl, url);
    bool found = visitedUrls.contains(norm, comparePtrsAsStrings);
    if (found)
        std::cout << "[DEBUG] Ya visitada: " << norm << std::endl;
    memFree(norm);
    return found;
}

void WebCrawler::markVisited(const char* url) {
    char* norm = normalizeUrl(this->rootUrl, url);
    std::cout << "[DEBUG] Marcando como visitada: " << norm << std::endl;
    visitedUrls.add(norm);
}
