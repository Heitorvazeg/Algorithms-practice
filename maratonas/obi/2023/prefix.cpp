#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    string p1;
    getline(cin, p1);

    int m;
    cin >> m;
    cin.ignore();

    string p2;
    getline(cin, p2);

    int maxi = max(n, m);
    int count = 0;
    for (int i = 0; i < maxi; i++) {
        if (p1[i] == p2[i]) {
            count++;

        } else {
            break;
        }
    }

    cout << count;
}