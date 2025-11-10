// Write a program to search a pattern in a given text using the KMP algorithm.

#include <iostream>
#include <vector>
using namespace std;

// Build LPS array (Longest Prefix Suffix)
void buildLPS(string pat, vector<int> &lps) {
    int len = 0, i = 1;
    lps[0] = 0;

    while (i < pat.length()) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } 
        else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP Pattern Search
void KMP(string txt, string pat) {
    int n = txt.length();
    int m = pat.length();
    
    vector<int> lps(m);
    buildLPS(pat, lps);

    int i = 0, j = 0;
    while (i < n) {
        if (txt[i] == pat[j]) {
            i++; 
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < n && txt[i] != pat[j]) {
            if (j != 0) 
                j = lps[j - 1];
            else 
                i++;
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    KMP(text, pattern);
    return 0;
}
