#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int h;
        cin >> h;

        long long result;
        result = pow(2, h);

        cout << result-1 << "\n";
    }
}