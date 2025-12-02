#include <bits/stdc++.h>

using namespace std;

long long modpow(long long x, long long n, long long m) {
    if (n == 0) return 1;
    if (x == 0) return 0;

    long long ans = modpow(x, n/2, m);
    ans = (ans * ans) % m;

    if (n % 2) {
        ans = (ans * x) % m;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;

        long long ans =  modpow(a, b, 1000000007);

        cout << ans << "\n";
    }
}