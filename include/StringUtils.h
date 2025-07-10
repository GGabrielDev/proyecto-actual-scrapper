#ifndef STRING_UTILS_H
#define STRING_UTILS_H

void copyString(char* dest, const char* src, int maxLen);
void copyPartialString(char* dest, const char* src, int length);
int compareString(const char* a, const char* b);
int stringLength(const char* str);
char* extractDomain(const char* url);
char* stripUrlParameters(const char* url);
char* normalizeUrl(const char* baseUrl, const char* href);
char* buildAbsoluteUrl(const char* baseUrl, const char* relativePath);
bool comparePtrsAsStrings(void* a, void* b);
char* stringDuplicate(const char* str);
char* findChar(char* str, char c);
bool startsWith(const char* str, const char* prefix);
void shiftLeft(char* str, int n);
bool stringEquals(const char* a, const char* b);  // para usar con contains

#endif // STRING_UTILS_H
