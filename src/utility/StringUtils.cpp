#include "StringUtils.h"
#include "MemoryUtils.h"

void copyString(char* dest, const char* src, int maxLen) {
    int i = 0;
    while (i < maxLen - 1 && src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
}

void copyPartialString(char* dest, const char* src, int length) {
    if (!dest || !src || length < 0) return;

    for (int i = 0; i < length; ++i) {
        dest[i] = src[i];
    }
    dest[length] = '\0';
}

int compareString(const char* a, const char* b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return a[i] - b[i];
        ++i;
    }
    return a[i] - b[i];
}

int stringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        ++length;
    }
    return length;
}

char* extractDomain(const char* url) {
    // Extrae hasta el tercer '/' (después de "https://")
    int slashCount = 0;
    int i = 0;
    while (url[i] != '\0') {
        if (url[i] == '/') slashCount++;
        if (slashCount == 3) break;
        i++;
    }

    int len = i;
    char* domain = (char*)memAlloc(len + 1);
    for (int j = 0; j < len; ++j) domain[j] = url[j];
    domain[len] = '\0';
    return domain;
}

// Crea una nueva cadena que contiene solo la parte base de una URL, sin parámetros ni anclas
char* stripUrlParameters(const char* url) {
    int i = 0;
    while (url[i] != '\0' && url[i] != '?' && url[i] != '#') {
        ++i;
    }

    char* clean = (char*)memAlloc(i + 1);
    copyPartialString(clean, url, i);
    clean[i] = '\0';
    return clean;
}

char* normalizeUrl(const char* baseUrl, const char* href) {
    if (!href || stringLength(href) == 0) return nullptr;

    char* fullUrl = nullptr;

    // Si ya es absoluta
    if (startsWith(href, "http://") || startsWith(href, "https://")) {
        fullUrl = stringDuplicate(href);
    } else {
        // Combina con el dominio base manualmente
        char* domain = extractDomain(baseUrl);  // ejemplo: https://site.com
        int domainLen = stringLength(domain);
        int hrefLen = stringLength(href);

        fullUrl = (char*)memAlloc(domainLen + hrefLen + 2);

        copyString(fullUrl, domain, domainLen + 1);

        if (domain[domainLen - 1] != '/' && href[0] != '/') {
            fullUrl[domainLen] = '/';
            copyString(fullUrl + domainLen + 1, href, hrefLen + 1);
        } else {
            copyString(fullUrl + domainLen, href, hrefLen + 1);
        }

        memFree(domain);
    }

    // Eliminar anclas y parámetros
    int i = 0;
    while (fullUrl[i] != '\0') {
        if (fullUrl[i] == '#' || fullUrl[i] == '?') {
            fullUrl[i] = '\0';
            break;
        }
        ++i;
    }

    // Eliminar slash final innecesario
    int len = stringLength(fullUrl);
    if (len > 1 && fullUrl[len - 1] == '/') {
        fullUrl[len - 1] = '\0';
    }

    return fullUrl;
}

// Funcion auxiliar
char* copyNewString(const char* src) {
    int len = stringLength(src);
    char* dest = (char*)memAlloc(len + 1);
    copyString(dest, src, len + 1);
    return dest;
}

char* buildAbsoluteUrl(const char* baseUrl, const char* relativePath) {
    if (!relativePath || relativePath[0] == '\0') return nullptr;

    if (relativePath[0] == 'h' && relativePath[1] == 't') {
        // Ya es una URL absoluta
        return copyNewString(relativePath);  // Usa memAlloc y copy internamente
    }

    char* baseDomain = extractDomain(baseUrl);  // e.g. https://example.com
    int baseLen = stringLength(baseDomain);
    int relLen = stringLength(relativePath);

    char* fullUrl = (char*)memAlloc(baseLen + relLen + 2);
    copyString(fullUrl, baseDomain, baseLen + 1);

    // Añadir '/' si hace falta
    if (baseDomain[baseLen - 1] != '/' && relativePath[0] != '/') {
        fullUrl[baseLen] = '/';
        copyString(fullUrl + baseLen + 1, relativePath, relLen + 1);
    } else {
        copyString(fullUrl + baseLen, relativePath, relLen + 1);
    }

    char* clean = normalizeUrl(fullUrl);
    memFree(fullUrl);
    return clean;
}


bool comparePtrsAsStrings(void* a, void* b) {
    return compareString(static_cast<char*>(a), static_cast<char*>(b)) == 0;
}

char* stringDuplicate(const char* str) {
    int len = stringLength(str);
    char* dup = (char*)memAlloc(len + 1);
    copyString(dup, str, len + 1);
    return dup;
}

char* findChar(char* str, char c) {
    while (*str != '\0') {
        if (*str == c) return str;
        ++str;
    }
    return nullptr;
}

bool startsWith(const char* str, const char* prefix) {
    int i = 0;
    while (prefix[i] != '\0') {
        if (str[i] != prefix[i]) return false;
        ++i;
    }
    return true;
}

void shiftLeft(char* str, int n) {
    int i = 0;
    while (str[i + n] != '\0') {
        str[i] = str[i + n];
        ++i;
    }
    str[i] = '\0';
}

bool stringEquals(const char* a, const char* b) {
    return compareString(a, b) == 0;
}
