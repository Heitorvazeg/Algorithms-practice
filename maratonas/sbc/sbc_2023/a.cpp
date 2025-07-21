#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    int n, h;
    cin >> n >> h;

    vector<int> vetor(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> vetor[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (vetor[i] <= h) {
            count++;
        }
    }

    cout << count;
}