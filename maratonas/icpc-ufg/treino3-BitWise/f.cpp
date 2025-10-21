#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int l = 0; l < t; l++) {
        unsigned long long m, n;
        unsigned int k;
        cin >> m >> n >> k;

        int count = 0;
        for (unsigned long long j = m; j <= n; j++) {
            unsigned long long shift = 1;
            long long ai = 0;
            long long bi = 0;
            for (unsigned long long i = 0; i <= 63; i++) {
                if ((i & shift) == 0) {
                    if (j & (shift << i)) {
                        ai++;
                    }

                } else if ((i & shift) == shift) {
                    if (j & (shift << i)) {
                        bi++;
                    }
                }
            }
            if (abs(ai - bi) == k) count++;
        }
        cout << count << "\n";
    }
}