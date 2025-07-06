#ifndef MEMORY_UTILS_H
#define MEMORY_UTILS_H

void* memCopy(void* dest, const void* src, int bytes);
void* memAlloc(int bytes);
void* memRealloc(void* ptr, int newSize);
void memFree(void* ptr);

#endif // MEMORY_UTILS_H
