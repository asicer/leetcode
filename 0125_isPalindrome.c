#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char *s) {
    int sSize = strlen(s);
    int i = 0, j = sSize-1;
    char ci, cj;
    while (i<j) {
        while (i<j) {
            if (!(isalpha(s[i])||isdigit(s[i])))
                i++;
            else
                break;
        }
        while (i<j) {
            if (!(isalpha(s[j])||isdigit(s[j])))
                j--;
            else
                break;
        }
        ci = s[i++];
        cj = s[j--];
        if (ci>='A' && ci<='Z')
            ci = ci + 'a' -'A';
        if (cj>='A' && cj<='Z')
            cj = cj + 'a' -'A';
        if (ci != cj)
            return false;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    printf("%d\n", isPalindrome(""));
    printf("%d\n", isPalindrome("0P"));
    printf("%d\n", isPalindrome("0P.:0 "));
    return 0;
}
