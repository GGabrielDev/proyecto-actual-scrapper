#include "LinkExtractor.h"
#include "StringUtils.h"
#include "MemoryUtils.h"
#include <iostream>

void extractLinks(const char* html, LinkedList* outLinks) { 
    const char* pattern = "href=\"";
    int patternLen = 6;

    int i = 0;
    while (html[i] != '\0') {
        // Buscar el patrón
        int j = 0;
        while (pattern[j] != '\0' && html[i + j] == pattern[j]) {
            ++j;
        }

        if (j == patternLen) {
            int start = i + patternLen;
            int end = start;

            // Buscar comilla de cierre
            while (html[end] != '\0' && html[end] != '"') {
                ++end;
            }

            int urlLength = end - start;
            if (urlLength > 0 && urlLength < 2048) { // protegerse
                char* url = (char*)memAlloc(urlLength + 1);
                for (int k = 0; k < urlLength; ++k) {
                    url[k] = html[start + k];
                }
                url[urlLength] = '\0';
                outLinks->addToEnd((void*)url);
            }

            i = end; // continuar desde el final del enlace
        } else {
            ++i;
        }
    }
}
