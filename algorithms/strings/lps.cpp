/* Longest Prefix "Suffix": 
Algoritmo de string que verifica o maior prefixo que tambem é um sufixo em uma string*/

#include <bits/stdc++.h>

using namespace std;

vector<int> computeLPS(const string& pat) {
    int m = pat.size();
    vector<int> lps(m, 0);

    int len = 0; // Comprimento do prefixo-sufixo anterior
    int i = 1;

    while (i < m) {
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
    return lps;
}