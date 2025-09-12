#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, x;
        cin >> n >> x;

        vector<int> coral(n);
        for (int j = 0; j < n; j++) {
            cin >> coral[j];
        }

        int c = 1;
        int min = 1;
        int max = 2000000;
        while (c <= max) {
            c = (min + max) / 2;
            long long sum = 0;
            for (int j = 0; j < n; j++) {
                if (coral[j] > c) {
                    sum += coral[j] - (coral[j] - c);
                    continue;
                }
                sum += coral[j];
            }

            if ((c*n)-sum > x) {
                max = c -1;

            } else if ((c*n)-sum < x) {
                min = c + 1;
            } else {
                break;
            }
        }

        cout << c-1 << "\n";
    }
}