// Given a text txt[0..N-1] and a pattern pat[0..M-1], write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[].
// Assume that N > M. 

// Examples:

// Input:  txt[] = "THIS IS A TEST TEXT", pat[] = "TEST"
// Output: Pattern found at index 10

// Input:  txt[] =  "AABAACAADAABAABA"
//           pat[] =  "AABA"
// Output: Pattern found at index 0, Pattern found at index 9, Pattern found at index 12

#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(char* pat, int M, int* lps);

void KMPSearch(char* pat, char* txt) {
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[M];
    computeLPSArray(pat, M, lps);
    int i = 0;
    int j = 0;
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            printf("Found pattern at index %d ", i - j);
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

void computeLPSArray(char* pat, int M, int* lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main() {
    char txt[1000];
    char pat[1000];
    cout << "Enter the text: ";
    cin.getline(txt, 1000);
    cout << "Enter the pattern: ";
    cin.getline(pat, 1000);
    KMPSearch(pat, txt);
    return 0;
}


