#include "string.h"
char *strncat(char *dest, char *src, int n) {

    while (*dest != '\0') {
        dest++;
    }

    while (n--) {
        *dest++ = *src++;
    }
    *dest = '\0';
    return dest;
}

char *strcat(char *dest, char *src) {

    while (*dest != '\0') {
        dest++;
    }

    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';
    return dest;
}

int strncmp(char *s1, char *s2, int n) {
    for (n; n && *s1 && *s2 && *s1 == *s2; s1++, s2++, n--);
    return *s1 - *s2;
}

int strcspn(char *s1, char *s2) {
    int i, j;
    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j])
                return i;
        }
    }
    return i;
}

int strspn(char *s1, char *s2) {
    int i, j;
    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j])
                break;
        }
        if (!s2[j])
            break;
    }
    return i;
}

int strlen(char *src) {
    int len;
    for (len = 0; src[len]; len++);
    return len;
}

void *memcpy(void *dest, void *src, unsigned int n) {
    char *to = (char *) dest;
    char *from = (char *) src;
    while (n--) {
        *to++ = *from++;
    }
}
