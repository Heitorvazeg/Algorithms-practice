#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> notas(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> notas[i];
    }

    sort(notas.begin(), notas.end(), greater<>());

    for (int i = 0; i < n; i++) {
        int max = notas[i];
        int min = 1000;
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (notas[j] >= max) {
                count++;
                if (notas[j] < min) {
                    min = notas[j];
                }
            }
        }

        if (count >= k) {
            cout << min;
            break;
        }
    }
}