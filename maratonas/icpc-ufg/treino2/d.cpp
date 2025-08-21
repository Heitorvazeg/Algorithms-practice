#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 

    int n;
    cin >> n;

    unordered_map<int, int> bolsa;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a;

        if (a != 3) {
            cin >> b;
        }

        if (a == 1) {
            if (bolsa.count(b)) {
                bolsa[b]++;
                continue;
            }
            bolsa[b] = 1;
        }

        if (a == 2) {
            bolsa[b]--;
            if (bolsa[b] <= 0) {
                bolsa.erase(b);
                continue;
            }
        }

        if (a == 3) {
            cout << bolsa.size() << "\n";
        }
    }
}