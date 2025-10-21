#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> vec(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> vec[i][j];
        }
    }

    int soma = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            soma += vec[j][i];
        }
        if (soma != 0) {
            cout << "NO";
            return 0;
        }
    }
    if (soma == 0) {
        cout << "YES";
        return 0;
    }
}