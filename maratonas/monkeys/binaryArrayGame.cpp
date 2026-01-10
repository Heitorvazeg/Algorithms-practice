#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;

        cin >> n;

        vector<int> binaryArray(n, 0);

        for (int i = 0; i < n; i++) cin >> binaryArray[i];

        if (binaryArray[0] == 0 && binaryArray[n-1] == 0) {
            cout << "Bob\n";

        } else {
            cout << "Alice\n";
        }
    }
}