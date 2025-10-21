#include <bits/stdc++.h>

using namespace std;

long long checkQtd(vector<long long>& corais, long long h) {
    long long sum = 0;
    for (int i = 0; i < (int)corais.size(); i++) {
        if (h > corais[i]) sum += h - corais[i];
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        long long x;
        cin >> n >> x;

        vector<long long> corais(n, 0);
        long long ma = 0;
        for (int j = 0; j < n; j++) {
            cin >> corais[j];
            ma = max(ma, corais[j]);
        }

        long long e = 0;
        long long d = x + ma;
        long long ans = 0;
        while (e <= d) {
            long long h = (e+d)/2;

            long long qtd = checkQtd(corais, h);

            if (qtd <= x) {e = h + 1; ans = h;}
            else if (qtd > x) d = h - 1;
        }

        cout << ans << "\n";
    }
}