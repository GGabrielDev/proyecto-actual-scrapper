#include "MemoryUtils.h"

void* memCopy(void* dest, const void* src, int bytes) {
    char* d = (char*)dest;
    const char* s = (const char*)src;
    for (int i = 0; i < bytes; ++i) {
        d[i] = s[i];
    }
    return dest;
}

void* memAlloc(int bytes) {
    char* block = new char[bytes];
    return (void*)block;
}

void* memRealloc(void* ptr, int newSize) {
    if (!ptr) return memAlloc(newSize);

    // Suponemos que el buffer anterior es más pequeño (no sabemos cuánto).
    // Estrategia: crear nuevo y copiar hasta `newSize` con cuidado.
    char* oldPtr = (char*)ptr;
    char* newPtr = new char[newSize];
    for (int i = 0; i < newSize; ++i) {
        newPtr[i] = oldPtr[i];
    }

    delete[] oldPtr;
    return (void*)newPtr;
}

void memFree(void* ptr) {
    delete[] (char*)ptr;
}
