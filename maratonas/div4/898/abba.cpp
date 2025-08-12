#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;

        int itE = 0;
        int itD = 0;
        int coins = 0;
        while (itE < (int)s.size()) {
            itD++;
            string um(1, s[itE]);
            string dois(1, s[itD]);
            string st = um + dois;
            if (st == "AB") {
                s[itE] = 'B';
                s[itD] = 'C';
                coins++;
            
            } else if (st == "BA") {
                s[itE] = 'C';
                s[itD] = 'B';
                coins++;
            }

            itE++;
            itD++;
        }
        cout << coins << "\n";
    }
}