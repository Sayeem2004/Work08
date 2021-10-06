#include <stdio.h>
#include <stdlib.h>

int mystrlen(char *s) {
    char *cs = s;
    int cnt = 0;
    while (*cs) {
        cnt++; cs++;
    }
    return cnt;
}

char *mystrcpy(char *dest, char *source) {
    char *cdest = dest, *csource = source;
    while (*csource) {
        *cdest = *csource;
        cdest++; csource++;
    }
    *cdest = 0;
    return dest;
}

char *mystrncpy(char *dest, char *source, int n) {
    char *cdest = dest, *csource = source;
    while (*csource && n) {
        *cdest = *csource;
        cdest++; csource++; n--;
    }
    while (n) {
        *cdest = '\0';
        cdest++; n--;
    }
    return dest;
}

char* mystrcat(char *dest, char *source) {
    char *cdest = dest, *csource = source;
    while (*cdest) cdest++;
    while (*csource) {
        *cdest = *csource;
        cdest++; csource++;
    }
    *cdest = 0;
    return dest;
}

char* mystrncat(char *dest, char *source, int n) {
    char *cdest = dest, *csource = source;
    while (*cdest) cdest++;
    while (*csource && n) {
        *cdest = *csource;
        cdest++; csource++; n--;
    }
    while (n) {
        *cdest = '\0';
        cdest++; n--;
    }
    *cdest = 0;
    return dest;
}

int mystrcmp(char *s1, char *s2) {
    char *cs1 = s1, *cs2 = s2;
    while (*cs1 == *cs2) {
        if (*cs1 == '\0' || *cs2 == '\0') break;
        cs1++; cs2++;
    }
    return ((*cs1)-(*cs2) > 0 ? 1 : (*cs1)-(*cs2) < 0 ? -1 : 0);
}

char* mystrchr(char *s, char c) {
    char *cs = s;
    while (*cs) {
        if (*cs == c) break;
        cs++;
    }
    return (*cs == c ? cs : NULL);
}

char* mystrstr(char *s1, char *s2) {
    char *cs1 = s1, *cs2 = s2;
    if (*cs2 == '\0') return s1;
    while (*cs1) {
        if (*cs1 == *cs2) {
            char *ccs1 = cs1, *ccs2 = cs2;
            while (*ccs1 == *ccs2) {
                if (*ccs1 == '\0' || *ccs2 == '\0') break;
                ccs1++; ccs2++;
            }
            if (*ccs2 == '\0') return cs1;
        }
        cs1++;
    }
    return NULL;
}
