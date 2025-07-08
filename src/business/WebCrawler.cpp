#include "LinkExtractor.h"
#include "MemoryUtils.h"
#include "WebCrawler.h"
#include "WebFetcher.h"
#include <iostream> // Para demostración

WebCrawler::WebCrawler() : navigationTree(new NavigationTree()) {}

WebCrawler::~WebCrawler() {
    delete navigationTree;
}

void WebCrawler::crawl(const char* rootUrl, int maxDepth) {
    if (isVisited(rootUrl) || maxDepth < 0) {
        return;
    }

    // Guardamos rootUrl para usarlo luego en countLinks
    int len = stringLength(rootUrl) + 1;
    this->rootUrl = (char*)memAlloc(len);
    copyString(this->rootUrl, rootUrl, len);

    markVisited(rootUrl);
    navigationTree->addNode(rootUrl, nullptr); // Añadir raíz

    char* html = fetchPage(rootUrl);

    if (!html) {
        std::cout << "[WARN] Falló fetch de: " << rootUrl << std::endl;
        return;
    }

    LinkedList links;
    extractLinks(html, &links);


    for (int i = 0; i < links.size(); ++i) {
        char* childUrl = static_cast<char*>(links.get(i));

        // Ignorar enlaces vacíos o anclas
        if (stringLength(childUrl) == 0 || childUrl[0] == '#') {
            memFree(childUrl);
            continue;
        }

        // Verificar si es del mismo dominio (simulado por prefijo simple)
        bool isInternal = false;
        int rootLen = stringLength(rootUrl);
        int childLen = stringLength(childUrl);

        if (childLen >= rootLen) {
            bool matches = true;
            for (int j = 0; j < rootLen && matches; ++j) {
                if (rootUrl[j] != childUrl[j]) matches = false;
            }
            isInternal = matches;
        }

        // TreeNode* parentNode = navigationTree->findNode(rootUrl);
        // if (!parentNode) {
        //     std::cout << "[ERROR] Nodo raíz no encontrado para: " << rootUrl << std::endl;
        //     memFree(html);
        //     return;
        // }
        // navigationTree->addNode(childUrl, parentNode);
        
        TreeNode* parentNode = navigationTree->findNode(rootUrl);
        if (!parentNode) {
            std::cout << "[ERROR] findNode falló para: " << rootUrl << std::endl;
            continue; // Evita crash
        }
        navigationTree->addNode(childUrl, parentNode);

        if (isInternal && !isVisited(childUrl)) {
            crawl(childUrl, maxDepth - 1);
        }

        memFree(childUrl);
    }

    memFree(html);
}

int WebCrawler::countLinks() const {
    LinkStats stats = navigationTree->computeStats(rootUrl); // ← rootUrl debe ser guardado
    std::cout << "[INFO] Total: " << stats.total
              << ", Internos: " << stats.internal
              << ", Externos: " << stats.external
              << ", Profundidad: " << stats.maxDepth
              << std::endl;
    return stats.total;
}

bool WebCrawler::findKeyword(const char* keyword) const {
    // Placeholder para la logica de busqueda
    return false;
}

void WebCrawler::detectBrokenLinks() const {
    // Placeholder para la logica de enlaces rotos
}

bool WebCrawler::isVisited(const char* url) const {
    for (int i = 0; i < visitedUrls.size(); ++i) {
        if (compareString(static_cast<const char*>(visitedUrls.get(i)), url) == 0) {
            return true;
        }
    }
    return false;
}

void WebCrawler::markVisited(const char* url) {
    int length = stringLength(url) + 1;
    char* urlCopy = new char[length];
    copyString(urlCopy, url, length);
    visitedUrls.add(static_cast<void*>(urlCopy));
}
