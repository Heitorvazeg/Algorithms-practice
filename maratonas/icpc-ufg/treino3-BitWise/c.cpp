#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> arms(m+1, 0);
    for (int i = 0; i < m+1; i++) {
        cin >> arms[i];
    }

    int s = (int)arms.size();

    int ans = 0;
    for (int i = s-1; i >= 0; i--) {
        if (i == s-1) continue;
        int count = 0;
        int aux = arms[s-1]^arms[i];

        for (int j = 31; j >= 0; j--) {
            if (aux & (1 << j)) {
                count++;
            }
        }

        if (count <= k) ans++;
    }

    cout << ans;
}