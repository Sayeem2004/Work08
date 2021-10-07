#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystring.h"

int main() {
    char s1[100];
    char s2[100] = "hello";
    char s3[100] = "goodbye";

    printf("start strings:\n");
    printf("s1: [%s]\n", s1);
    printf("s2: [%s]\n", s2);
    printf("s3: [%s]\n", s3);

    printf("\nTesting strlen(s2):\n");
    printf("[standard]:\t%lu\n", strlen(s2));
    printf("[mine]:\t\t%d\n", mystrlen(s2));

    printf("\nTesting strcpy(s1, s2):\n");
    printf("[standard]:\t[%s]\n", strcpy(s1, s2));
    printf("[mine]:\t\t[%s]\n", mystrcpy(s1, s2));

    printf("\nTesting strncpy(s1, s3, 3):\n");
    printf("[standard]:\t[%s]\n", strncpy(s1, s3, 3));
    printf("[mine]:\t\t[%s]\n", mystrncpy(s1, s3, 3));

    printf("\nTesting strcat(s1, s3):\n");
    printf("[standard]:\t[%s]\n", strcat(s1, s3));
    s1[5] = 0;
    printf("[mine]:\t\t[%s]\n", mystrcat(s1, s3));

    printf("\nTesting strncat(s1, s2, 3):\n");
    printf("[standard]:\t[%s]\n", strncat(s1, s2, 3));
    s1[12] = 0;
    printf("[mine]:\t\t[%s]\n", mystrncat(s1, s2, 3));

    printf("\nTesting strchr(s1, 'l'):\n");
    printf("[standard]:\t[%p]\n", strchr(s1, 'l'));
    printf("[mine]:\t\t[%p]\n", mystrchr(s1, 'l'));

    printf("\nTesting strchr(s1, 0):\n");
    printf("[standard]:\t[%p]\n", strchr(s1, 0));
    printf("[mine]:\t\t[%p]\n", mystrchr(s1, 0));

    printf("\nTesting strchr(s1, 'z'):\n");
    printf("[standard]:\t[%p]\n", strchr(s1, 'z'));
    printf("[mine]:\t\t[%p]\n", mystrchr(s1, 'z'));

    printf("\nTesting strcmp\n");
    printf("\tComparing ab to abc:\n");
    printf("\t\t[standard]:\t[%d]\n", strcmp("ab", "abc"));
    printf("\t\t[mine]:\t\t[%d]\n", mystrcmp("ab", "abc"));
    printf("\tComparing abc to ab:\n");
    printf("\t\t[standard]:\t[%d]\n", strcmp("abc", "ab"));
    printf("\t\t[mine]:\t\t[%d]\n", mystrcmp("abc", "ab"));
    printf("\tComparing abc to abc:\n");
    printf("\t\t[standard]:\t[%d]\n", strcmp("abc", "abc"));
    printf("\t\t[mine]:\t\t[%d]\n", mystrcmp("abc", "abc"));

    printf("\nTesting strstr\n");
    printf("\tSearching for abc in abababccc:\n");
    printf("\t\t[standard]:\t[%p]\n", strstr("abababccc", "abc"));
    printf("\t\t[mine]:\t\t[%p]\n", mystrstr("abababccc", "abc"));
    printf("\tSearching for ccb in abababccc:\n");
    printf("\t\t[standard]:\t[%p]\n", strstr("abababccc", "ccb"));
    printf("\t\t[mine]:\t\t[%p]\n", mystrstr("abababccc", "ccb"));
    printf("\tSearching for \"\\0\" in abababccc:\n");
    printf("\t\t[standard]:\t[%p]\n", strstr("abababccc", "\0"));
    printf("\t\t[mine]:\t\t[%p]\n", mystrstr("abababccc", "\0"));

    char *s4 = strdup("abc,def,ghi");
    char *s5 = strdup(s4);
    char *s6 = strdup("abc,def,ghi");
    char *s7 = strdup(s6);
    char *s8 = strdup("\0");
    char *s9 = strdup(s8);
    printf("\nstart strings:\n");
    printf("s4: [%s]\n", s4);
    printf("s5: [%s]\n", s5);
    printf("s6: [%s]\n", s6);
    printf("s7: [%s]\n", s7);
    printf("s8: [%s]\n", s8);
    printf("s9: [%s]\n", s9);

    printf("\nTesting strsep(s4, \",\")\n");
    s5 = mysplit(s5,',');
    int i = 0;
    while (s4 != NULL) {
        printf("Iteration %d:\n", i); i++;
        printf("\t[standard]:\t[%s]\n", strsep(&s4,","));
        printf("\t[mine]:\t\t[%s]\n", s5);
        while (*s5 != '\0') s5++;
        s5++;
    }

    printf("\nTesting strsep(s6, \"z\")\n");
    s7 = mysplit(s7,'z');
    i = 0;
    while (s6 != NULL) {
        printf("Iteration %d:\n", i); i++;
        printf("\t[standard]:\t[%s]\n", strsep(&s6,"z"));
        printf("\t[mine]:\t\t[%s]\n", s7);
        while (*s7 != '\0') s7++;
        s7++;
    }

    printf("\nTesting strsep(s8, \"z\")\n");
    s9 = mysplit(s9,'z');
    i = 0;
    while (s8 != NULL) {
        printf("Iteration %d:\n", i); i++;
        printf("\t[standard]:\t[%s]\n", strsep(&s8,"\0"));
        printf("\t[mine]:\t\t[%s]\n", s9);
        while (*s9 != '\0') s9++;
        s9++;
    }
    
    return 0;
}
