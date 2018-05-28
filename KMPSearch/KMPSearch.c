#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void computeLPSArray(char *arr, int n, int *pi) {
    pi[0] = -1;
    int i = 1;
    int j = 0;

    while (i < n) {
        if (arr[i] == arr[j]) {
            pi[i] = pi[j];
            i++;
            j++;
        } else {
            pi[i] = j;
            j = pi[j];
            while (j >= 0 && arr[j] != arr[i]) {
                j = pi[j];
            }
            i++;
            j++;
        }
    }
    pi[i] = j;

}

void KMPSearch(char *pat, char *txt) {

    int N = strlen(txt);
    int M = strlen(pat);
    int *lps = (int *) malloc(sizeof(int) * (M + 1));
    computeLPSArray(pat, M, lps);
    int i = 0; //txtnnnn n
    int j = 0; //pattern
    while (i < N) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
            if (j == M) {
                printf("Found pattern at index %d to index %d\n", i - j, i);
                j = lps[j];
            }
        } else {
            j = lps[j];
            if (j < 0) {
                i++;
                j++;
            }
        }
    }
    free(lps);
}


int main() {
    char *txt = "apurba mandal loves";
    char *pat = "loves";
    KMPSearch(pat, txt);
    return 0;
}