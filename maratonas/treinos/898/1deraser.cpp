#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        cin.ignore();

        string s;
        cin >> s;

        int count = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'B') {
                count++;
                j += k-1;
            }
        }

        cout << count << "\n";
    }
}