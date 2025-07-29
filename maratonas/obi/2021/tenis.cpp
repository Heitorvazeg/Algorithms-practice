#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<char> vetor(6, 'V');
    for (int i = 0; i < 6; i++) {
        cin >> vetor[i];
    }

    int count = 0;
    for (int i = 0; i < 6; i++) {
        if (vetor[i] == 'V') {
            count++;
        }
    }

    if (count >= 5) {
        cout << 1;

    } else if (count == 3 || count == 4) {
        cout << 2;

    } else if (count == 2 || count == 1) {
        cout << 3;

    } else if (count == 0) {
        cout << -1;
    }
}