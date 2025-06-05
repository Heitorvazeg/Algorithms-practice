#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    getline(cin, s);

    if (s.size() == 8) {
        bool ok = true;
        for (int i = 0; i < 3; i++) {
            if (!isupper(s[i])) ok = false;
        }
        if (s[3] != '-') ok = false;
        for (int i = 4; i < 8; i++) {
            if (!isdigit(s[i])) ok = false;
        }
        if (ok) cout << 1 << '\n';
        else cout << 0 << '\n';

    } else if (s.size() == 7) {
        bool ok = true;
        if (!isupper(s[0]) || !isupper(s[1]) || !isupper(s[2])) ok = false;
        if (!isdigit(s[3])) ok = false;
        if (!isupper(s[4])) ok = false;
        if (!isdigit(s[5]) || !isdigit(s[6])) ok = false;

        if (ok) cout << 2 << '\n';
        else cout << 0 << '\n';
    } else {
        cout << 0 << '\n';
    }

    return 0;
}
