#include <bits/stdc++.h>

using namespace std;

vector<int> calCrivo(int x) {
    vector<int> c(x, -1);
    for (int i = 1; i <= x; i++) {
        for (int j = i; j <= x; j+=i) {
            if (j%i == 0) {
                if (c[j] == -1) c[j] = 1;
                else c[j]++;
            }
        }
    }

    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> cri = calCrivo(1e6);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        cout << cri[x] << "\n";
    }
}