#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    vector<long long> fi(500000, 0);
    fi[0] = 0;
    fi[1] = 1;
    for (long long i = 2; i <= 5*100000; i++) {
        fi[i] = (fi[i-1] + fi[i-2]) % 100000007;
    }

    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;

        long long ans = fi[num];

        cout << ans << "\n";
    }
}