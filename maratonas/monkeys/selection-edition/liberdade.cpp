#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int maxi = 1;
    int aux = 1;
    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i-1] != s[i]) {
            aux++;
        } else {
            maxi = max(maxi, aux);
            aux = 1;
        }
    }
    maxi = max(maxi, aux);
    cout << maxi;
}