#include "WebCrawler.h"
#include <iostream> // Para demostración

WebCrawler::WebCrawler() : navigationTree(new NavigationTree()) {}

WebCrawler::~WebCrawler() {
    delete navigationTree;
}

void WebCrawler::crawl(const char* rootUrl, int maxDepth) {
    if (isVisited(rootUrl)) {
        return;
    }

    markVisited(rootUrl);
    navigationTree->addNode(rootUrl, nullptr);

    // Simula logica de navegación
    std::cout << "Crawling: " << rootUrl << " at depth " << maxDepth << std::endl;

    // Aqui va la logica para halar la pagina y evaluarla, proseguido de recursivamente navegar los links.
}

int WebCrawler::countLinks() const {
    // Placeholder para la logica de conteo
    return 0;
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
