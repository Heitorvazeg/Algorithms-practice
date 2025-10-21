#include <bits/stdc++.h>

using namespace std;

long long check(long long mid, vector<long long> v) {
    long long sum = 0;
    long long qtd = 1;
    for (auto x : v) {
        if (sum + x > mid) {
            qtd++;
            sum = 0;
        }
        sum += x;
    }

    return qtd;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<long long> v(n, 0);
    long long ma = 0;
    long long soma = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        ma = max(ma, v[i]);
        soma += v[i];
    }

    long long ans = 0;
    while (ma <= soma) {
        long long mid = (ma+soma)/2;

        long long qtd = check(mid, v);
        if (qtd <= k) {
            ans = mid;
            soma = mid - 1;
        }
        else if (qtd > k) ma = mid + 1;
    }

    cout << ans << "\n";
}