#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        if (n%2) {cout << "0" << "\n"; continue;}

        int quatroQtd = n/4;

        cout << quatroQtd+1 << "\n";
    }
}