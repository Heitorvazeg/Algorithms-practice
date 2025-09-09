#include <bits/stdc++.h>

using namespace std;

void creatingStr(set<string>& ans, string& permut, int n, vector<bool> esc, string& s) {
    if ((int)permut.size() == n) {
        ans.insert(permut);
        return;

    } else {
        for (int i = 0; i < n; i++) {
            if (esc[i]) continue;
            esc[i] = true;
            permut.push_back(s[i]);
            creatingStr(ans, permut, n, esc, s);
            permut.pop_back();
            esc[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    set<string> ans;
    string vAux;
    vector<bool> vB((int)s.size(), false);
    creatingStr(ans, vAux, (int)s.size(), vB, s);

    int count = ans.size();
    cout << count << "\n";
    for (auto it : ans) {
        cout << it << "\n";
    }
}