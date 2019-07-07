#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// This also works but next one is much more cleaner
/*
bool isLongPressedName(char *name, char *typed){
    int nameSize = strlen(name);
    if (nameSize == 0)
        return true;
    int typedSize = strlen(typed);
    if (nameSize > typedSize)
        return false;

    char nameC = name[0];
    int nameCount = 1;
    char typedC = typed[0];
    int typedCount = 1;
    int i=1,j=1;
    while (i<nameSize) {
        if (nameC != typedC)
            return false;
        while (i<nameSize) {
            if (name[i] == nameC) {
                i++;
                nameCount++;
            } else {
                break;
            }
        }
        while (j<typedSize) {
            if (typed[j] == typedC) {
                j++;
                typedCount++;
            } else {
                break;
            }
        }

        if (nameCount > typedCount)
            return false;
        nameC = name[i];
        nameCount = 1;
        typedC = typed[j];
        typedCount = 1;
    }
    return true;
}
*/

bool isLongPressedName(char *name, char *typed){
    char *p1=name, *p2=typed;
    while (p1!='\0') {
        if (*p1 != *p2) {
            return false;
        }
        while (*p1==*p2) {
            if (*p1=='\0')
                return true;
            p1++;
            p2++;
        }
        while (*p2 == *(p2-1)) {
            p2++;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {
    printf("%d\n", isLongPressedName("alex", "aaleex"));
    printf("%d\n", isLongPressedName("vtkgn", "vttkgnn"));
    printf("%d\n", isLongPressedName("pyplrz", "ppyypllr"));
    return 0;
}
