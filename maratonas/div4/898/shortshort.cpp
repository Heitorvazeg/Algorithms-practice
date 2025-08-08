#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();

    for (int i = 0; i < t; i++) {
        string line;
        string a = "abc";
        getline(cin, line);

        int c = 0;
        for (int l = 0; l < 3; l++) {
            if (line[l] == a[l]) c++;
        }
        if (c > 0) {
            cout << "YES" << "\n";

        } else {
            cout << "NO" << "\n";
        }
    }
}