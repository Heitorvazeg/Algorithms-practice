#include <bits/stdc++.h>

// Confusa, confusa...

using namespace std;

void acharPrimeiro(unordered_map<string, int>& m, vector<vector<string>>& v, vector<int>& valL, vector<int>& valC) {
    for (int i = 0; i < (int)v.size(); i++) {
        string val = v[i][0];
        for (int j = 1; j < (int)v[i].size(); j++) {
            if (v[i][j] != val) break;
            if (j == (int)v[i].size()-1) {
                m[v[i][j]] = valL[i]/(int)v.size();
                cout << m[v[i][j]];
                return;
            }
        }
    }

    for (int i = 0; i < (int)v.size(); i++) {
        string val = v[0][i];
        for (int j = 1; j < (int)v[i].size(); j++) {
            if (v[j][i] != val) break;
            if (j == (int)v[i].size()-1) {
                m[v[j][i]] = valC[i]/(int)v[i].size();
                cout << m[v[j][i]];
                return;
            }
        }
    }
}

void acharValor(unordered_map<string, int>& m, vector<vector<string>>& v, vector<int>& valL, vector<int>& valC) {
    for (int i = 0; i < (int)v.size(); i++) {
        int c = 0;
        for (int j = 0; j < (int)v[i].size(); j++) {
            if (m.count(v[i][j])) {
                c++;
            }
        }
        if (c == (int)v[i].size() - 1) {
            for (int j = 0; j < (int)v[i].size(); j++) {
                int a = 1;
                if (!m.count(v[i][j])) {
                    if (j == 0) a = a*(-1);
                    m[v[i][j]] = valL[i]-(m[v[i][j-a]]*((int)v[i].size()-1));
                    cout << v[j][i] << " " << m[v[j][i]] << "\n";
                    return;
                }
            }
        }
    }

    for (int i = 0; i < (int)v.size(); i++) {
        int c = 0;
        for (int j = 0; j < (int)v[i].size(); j++) {
            if (m.count(v[j][i])) {
                c++;
            }
        }
        if (c == (int)v[i].size() - 1) {
            for (int j = 0; j < (int)v[i].size(); j++) {
                int a = 1;
                if (!m.count(v[j][i])) {
                    if (j == 0) a = a*(-1);
                    m[v[j][i]] = valC[i]-(m[v[j][i-a]]*((int)v[i].size()-1));
                    cout << v[j][i] << " " << m[v[j][i]] << "\n";
                    return;
                }
            }
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l, c;
    cin >> l >> c;
    
    vector<vector<string>> v(l, vector<string>(c));
    vector<int> valL(l, 0);
    vector<int> valC(c, 0);
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            cin >> v[i][j];
        }
        cin >> valL[i];
    }

    for (int i = 0; i < c; i++) {
        cin >> valC[i];
    }

    unordered_map<string, int> m;
    acharPrimeiro(m, v, valL, valC);
    for (int i = 0; i < (int)valL.size()+(int)valC.size(); i++) {
        acharValor(m, v, valL, valC);
    }

    vector<pair<string, int>> ans;
    for (auto& val : m) {
        ans.push_back({val.first, val.second});
    }

    sort(ans.begin(), ans.end());

    for (auto& val : ans) {
        cout << val.first << " " << val.second << "\n";
    }
}