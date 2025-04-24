#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "incrstring.h"

void test_strempty() {
    printf("Test: Check if a string is empty using 'strempty'.\n");
    printf("Empty string: %d (Expected: 1)\n", strempty(""));
    printf("Non-empty string: %d (Expected: 0)\n", strempty("Test"));
    printf("\n");
}

void test_strew() {
    printf("Test: Check if a string ends with a specific character using 'strew'.\n");
    printf("Ends with 't': %d (Expected: 1)\n", strew("Test", 't'));
    printf("Does not end with 'x': %d (Expected: 0)\n", strew("Test", 'x'));
    printf("\n");
}

void test_strsw() {
    printf("Test: Check if a string starts with a specific character using 'strsw'.\n");
    printf("Starts with 'T': %d (Expected: 1)\n", strsw("Test", 'T'));
    printf("Does not start with 'x': %d (Expected: 0)\n", strsw("Test", 'x'));
    printf("\n");
}

void test_strfpos() {
    printf("Test: Get the first position of a substring using 'strfpos'.\n");
    printf("First position of 'es': %ld (Expected: 1)\n", strfpos("Test", "es"));
    printf("Substring not found: %ld (Expected: -1)\n", strfpos("Test", "xyz"));
    printf("\n");
}

void test_strlpos() {
    printf("Test: Get the last position of a substring using 'strlpos'.\n");
    printf("Last position of 'es': %ld (Expected: 1)\n", strlpos("Test", "es"));
    printf("Substring not found: %ld (Expected: -1)\n", strlpos("Test", "xyz"));
    printf("\n");
}

void test_strins() {
    printf("Test: Insert a substring at a specific position using 'strins'.\n");
    char buffer[50] = "Hello, World!";
    printf("Before: %s\n", buffer);
    strins(buffer, 7, "Beautiful ");
    printf("After: %s (Expected: Hello, Beautiful World!)\n", buffer);
    printf("\n");
}

void test_strinsl() {
    printf("Test: Insert a substring at the left of a string using 'strinsl'.\n");
    char buffer[50] = "World!";
    printf("Before: %s\n", buffer);
    strinsl(buffer, "Hello, ");
    printf("After: %s (Expected: Hello, World!)\n", buffer);
    printf("\n");
}

void test_strinsr() {
    printf("Test: Append a substring at the right of a string using 'strinsr'.\n");
    char buffer[50] = "Hello, ";
    printf("Before: %s\n", buffer);
    strinsr(buffer, "World!");
    printf("After: %s (Expected: Hello, World!)\n", buffer);
    printf("\n");
}

void test_strtolwr() {
    printf("Test: Convert a string to lowercase using 'strtolwr'.\n");
    char buffer[] = "HELLO, WORLD!";
    printf("Before: %s\n", buffer);
    strtolwr(buffer);
    printf("After: %s (Expected: hello, world!)\n", buffer);
    printf("\n");
}

void test_strtoupr() {
    printf("Test: Convert a string to uppercase using 'strtoupr'.\n");
    char buffer[] = "hello, world!";
    printf("Before: %s\n", buffer);
    strtoupr(buffer);
    printf("After: %s (Expected: HELLO, WORLD!)\n", buffer);
    printf("\n");
}

void test_strtoopp() {
    printf("Test: Toggle case for each character in a string using 'strtoopp'.\n");
    char buffer[] = "Hello, World!";
    printf("Before: %s\n", buffer);
    strtoopp(buffer);
    printf("After: %s (Expected: hELLO, wORLD!)\n", buffer);
    printf("\n");
}

void test_strtrim() {
    printf("Test: Trim spaces from both sides of a string using 'strtrim'.\n");
    char buffer[] = "   Hello, World!   ";
    printf("Before: '%s'\n", buffer);
    strtrim(buffer);
    printf("After: '%s' (Expected: 'Hello, World!')\n", buffer);
    printf("\n");
}

void test_strrvrs() {
    printf("Test: Reverse the order of characters in a string using 'strrvrs'.\n");
    char buffer[] = "Hello, World!";
    printf("Before: %s\n", buffer);
    strrvrs(buffer);
    printf("After: %s (Expected: !dlroW ,olleH)\n", buffer);
    printf("\n");
}

void test_strcount() {
    printf("Test: Count occurrences of a substring in a string using 'strcount'.\n");
    printf("Count of 'l' in 'Hello, World!': %zu (Expected: 3)\n", strcount("Hello, World!", "l"));
    printf("\n");
}

void test_strrem() {
    printf("Test: Remove a character at a specific index using 'strrem'.\n");
    char buffer[] = "Hello, World!";
    printf("Before: %s\n", buffer);
    strrem(buffer, 7);
    printf("After: %s (Expected: Hello, orld!)\n", buffer);
    printf("\n");
}

void test_strrep() {
    printf("Test: Replace all occurrences of a substring using 'strrep'.\n");
    char buffer[50] = "Hello, World! Hello!";
    printf("Before: %s\n", buffer);
    strrep(buffer, "Hello", "Hi");
    printf("After: %s (Expected: Hi, World! Hi!)\n", buffer);
    printf("\n");
}

void test_strfrep() {
    printf("Test: Replace the first occurrence of a substring using 'strfrep'.\n");
    char buffer[50] = "Hello, World! Hello!";
    printf("Before: %s\n", buffer);
    strfrep(buffer, "Hello", "Hi");
    printf("After: %s (Expected: Hi, World! Hello!)\n", buffer);
    printf("\n");
}

void test_strlrep() {
    printf("Test: Replace the last occurrence of a substring using 'strlrep'.\n");
    char buffer[50] = "Hello, World! Hello!";
    printf("Before: %s\n", buffer);
    strlrep(buffer, "Hello", "Hi");
    printf("After: %s (Expected: Hello, World! Hi!)\n", buffer);
    printf("\n");
}

void test_strsplit() {
    printf("Test: Split a string into substrings using a separator with 'strsplit'.\n");
    const char *str = "Hello,World,This,Is,Split";
    char **result = NULL;
    size_t count = strsplit(str, ",", 10, &result);
    printf("Split count: %zu (Expected: 5)\n", count);
    for (size_t i = 0; i < count; ++i) {
        printf("Part %zu: %s\n", i, result[i]);
        free(result[i]);
    }
    free(result);
    printf("\n");
}

int main() {
    test_strempty();
    test_strew();
    test_strsw();
    test_strfpos();
    test_strlpos();
    test_strins();
    test_strinsl();
    test_strinsr();
    test_strtolwr();
    test_strtoupr();
    test_strtoopp();
    test_strtrim();
    test_strrvrs();
    test_strcount();
    test_strrem();
    test_strrep();
    test_strfrep();
    test_strlrep();
    test_strsplit();

    return 0;
}
