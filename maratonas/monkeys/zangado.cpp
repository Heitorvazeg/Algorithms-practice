#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long p;
    cin >> n >> p;

    vector<long long> forca(n, 0);
    long long soma = 0;
    for (int i = 0; i < n; i++) {
        cin >> forca[i];
        soma += forca[i];
    }

    for (int j = 0; j < n; j++) {
        if (forca[j] >= p || soma-forca[j] >= p) {
            cout << "S" << "\n";
            continue;

        } else {
            cout << "N" << "\n";
            continue;
        }
    }
}