#include <stdio.h>
#include <memory.h>

#define NO_OF_CHARS 256

int max(int a, int b) {
    return (a > b) ? a : b;
}

void badCharHeuristic(char *str, int size, int badchar[NO_OF_CHARS]) {
    int i;

    for (i = 0; i < NO_OF_CHARS; ++i)
        badchar[i] = -1;

    // Fill the actual value of last occurrence of a character
    for (i = 0; i < size; ++i)
        badchar[(int) str[i]] = i;
}


void preprocess_strong_suffix(int *shift, int *bpos, char *pat, int m) {
    // m — pattern len
    int i = m, j = m + 1;
    bpos[i] = j;

    while (i > 0) {
        /*if character at position i-1 is not equivalent to
          character at j-1, then continue searching to right
          of the pattern for border */
        while (j <= m && pat[i - 1] != pat[j - 1]) {
            // each border is computed by checking if a shorter border that is
            // already known can be extended to the left by the same symbol.
            if (shift[j] == 0)
                shift[j] = j - i;

            j = bpos[j];
        }
        i--;
        j--;
        bpos[i] = j;
    }
}

//Preprocessing for case 2
void preprocess_case2(int *shift, int *bpos,
                      char *pat, int m) {
    int i, j;
    j = bpos[0];
    for (i = 0; i <= m; i++) {
        /* set the border postion of first character of pattern
           to all indices in array shift having shift[i] = 0 */
        if (shift[i] == 0)
            shift[i] = j;

        /* suffix become shorter than bpos[0], use the position of
           next widest border as value of j */
        if (i == j)
            j = bpos[j];
    }
}


void BMSearch(char *txt, char *pat) {
    int txtLen = strlen(txt);//n
    int patLen = strlen(pat);//m
    int badchar[NO_OF_CHARS];
    badCharHeuristic(pat, patLen, badchar);
    int bpos[patLen + 1], shift[patLen + 1];

    //initialize all occurence of shift to 0
    for (int i = 0; i < patLen + 1; i++) shift[i] = 0;

    //do preprocessing
    preprocess_strong_suffix(shift, bpos, pat, patLen);
    preprocess_case2(shift, bpos, pat, patLen);


    int j;
    int s = 0;
    while (s <= txtLen - patLen) {
        int j = patLen - 1;
        while (j >= 0 && pat[j] == txt[j + s]) {
            j--;
        }
        if (j < 0) {
            printf("Pattern occurs at shift = %d\n", s);
            //s += (s+patLen < txtLen)? patLen-badchar[txt[s+patLen]] : 1;
            if (patLen < txtLen) {
                s += patLen - badchar[txt[s + patLen]];
            } else {
                s += 1;
            }
        } else {
            //The max function is used to make sure that we get a positive shift.
            s += max(1, j - badchar[txt[s + j]]);
        }
    }

}

int main() {
    char txt[] = "ABAnfvsdnvdmvkrnrkmammaAmammaA";
    char pat[] = "mamma";
    BMSearch(txt, pat);
    return 0;
}
