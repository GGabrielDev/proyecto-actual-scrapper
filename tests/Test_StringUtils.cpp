#include <cassert>
#include <iostream>
#include "StringUtils.h"

void testCopyString() {
    char dest[20];
    copyString(dest, "Hello, World!", 20);
    assert(compareString(dest, "Hello, World!") == 0);

    copyString(dest, "Short", 20);
    assert(compareString(dest, "Short") == 0);

    copyString(dest, "This is a very long string", 10);
    assert(compareString(dest, "This is a") == 0);
}

void testCompareString() {
    assert(compareString("abc", "abc") == 0);
    assert(compareString("abc", "abd") < 0);
    assert(compareString("abd", "abc") > 0);
    assert(compareString("abc", "abcd") < 0);
    assert(compareString("abcd", "abc") > 0);
}

int main() {
    testCopyString();
    testCompareString();
    std::cout << "All StringUtils tests passed!" << std::endl;
    return 0;
}
