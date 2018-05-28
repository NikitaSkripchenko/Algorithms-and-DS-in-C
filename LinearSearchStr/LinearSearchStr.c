#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

int NativeStringSearch(char *txt, char *pat) {
    int txtLen = strlen(txt);
    int patLen = strlen(pat);
    if (patLen > txtLen) {
        return -1;
    }
    for (int i = 0; i < txtLen - patLen + 1; ++i) {
        int res = 0;
        for (int j = 0; j < patLen; ++j) {
            if (txt[i + j] != pat[j]) {
                break;
            }
            res++;
        }
        if (res == patLen) {
            printf("%d, %d", res, i);
            return 1;
        }
    }
    return -1;
}

int main() {
    char *txt = "dloves";
    char *pat = "loves";
    NativeStringSearch(txt, pat);

}