#include "StringUtils.h"
#include "MemoryUtils.h"
#include <cassert>
#include <iostream>

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

void testStringLength() {
    assert(stringLength("Hello") == 5);
    assert(stringLength("") == 0);
    assert(stringLength("A longer string") == 15);
}

void testStripUrlParameters() {
    const char* input1 = "https://example.com/page?param=value";
    const char* expected1 = "https://example.com/page";
    char* result1 = stripUrlParameters(input1);
    assert(compareString(result1, expected1) == 0);
    memFree(result1);

    const char* input2 = "https://example.com/page#section";
    const char* expected2 = "https://example.com/page";
    char* result2 = stripUrlParameters(input2);
    assert(compareString(result2, expected2) == 0);
    memFree(result2);

    const char* input3 = "https://example.com/page";
    char* result3 = stripUrlParameters(input3);
    assert(compareString(result3, input3) == 0);
    memFree(result3);

    std::cout << "[PASSED] testStripUrlParameters\n";
}

int main() {
    testCopyString();
    testCompareString();
    testStringLength();
    testStripUrlParameters();
    std::cout << "All StringUtils tests passed!" << std::endl;
    return 0;
}
