#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    vector<int> vetor(a, 0);
    for (int i = 0; i < a; i++) {
        cin >> vetor[i];
    }

    vector<int> s(b, 0);
    for (int i = 0; i < b; i++) {
        cin >> s[i];
    }

    vector<int> sRes;
    int ptr = 0;

    for (int i = 0; i < a; i++) {
        if (vetor[i] == s[ptr]) {
            sRes.push_back(vetor[i]);
            ptr++;
        }
    }

    if (sRes == s) {
        cout << "S";

    } else {
        cout << "N";
    }
}