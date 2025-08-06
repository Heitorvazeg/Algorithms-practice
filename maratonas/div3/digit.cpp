#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int a;
        cin >> a;

        if (a < 10) {
            cout << a << "\n";
        } else if (a < 100) { 
            string sa = to_string(a);
            char uni = sa[1];
            char dez = sa[0];

            int u = uni - '0';
            int d = dez - '0';
            int mini = min(u, d);
            cout << mini << "\n";
        } else if (a <= 1000) {
            if (a == 1000) {
                cout << "0\n";
                continue;
            }
            string sa = to_string(a);
            char uni = sa[2];
            char dez = sa[1];
            char cent = sa[0];

            int u = uni = '0';
            int d = dez - '0';
            int c = cent - '0';

            int mini = min(u, d);
            mini = min(mini, c);

            cout << mini << "\n";
        }
    }
}