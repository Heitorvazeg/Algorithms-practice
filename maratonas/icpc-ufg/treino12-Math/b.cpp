#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    cin >> a >> b;

    long long ans = gcd(a, b);

    cout << ans << '\n';
}