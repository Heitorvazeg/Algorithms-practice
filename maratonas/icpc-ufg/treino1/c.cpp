#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int num;
        if ((int)s.size() > 10) {
            num = s.size() - 2;

        } else {
            cout << s << "\n";
            continue;
        }
        string sR = s[0] + to_string(num) + s[s.size()-1];
        cout << sR << "\n";
    }
}