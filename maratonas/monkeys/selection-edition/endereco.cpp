#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    getline(cin, s);

    unordered_map<char, bool> m;
    m['a'] = true;
    m['e'] = true;
    m['i'] = true;
    m['o'] = true;
    m['u'] = true;
    m['A'] = true;
    m['E'] = true;
    m['I'] = true;
    m['O'] = true;
    m['U'] = true;

    int count = 0;

    for (int i = 0; i < (int)s.size(); i++) {
        if (m.count(s[i])) count++;
    }

    cout << count%3;
}