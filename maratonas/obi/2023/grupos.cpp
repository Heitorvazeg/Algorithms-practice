#include <bits/stdc++.h>

using namespace std;

int validarGrupos(vector<vector<int>>& grupos, vector<pair<int, int>>& msmGrupo, vector<pair<int, int>>& difGrupo, int e) {
    for (int i = 0; i < e/3; i++) {
        for (int j = 0; j < msmGrupo.size(); j++) {
            if (msmGrupo[j].first);
        }
    }

    for (int i = 0; i < e/3; i++) {
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int e, m, d;
    cin >> e >> m >> d;

    vector<pair<int, int>> msmGrupo(m, pair<int, int>(0, 0));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        msmGrupo[i].first = a;
        msmGrupo[i].second = b;
    }

    vector<pair<int, int>> difGrupo(d, pair<int, int>(0, 0));
    for (int i = 0; i < d; i++) {
        int a, b;
        cin >> a >> b;
        difGrupo[i].first = a;
        difGrupo[i].second = b;
    }

    vector<vector<int>> grupos(e/3, vector<int>(3));
    for (int i = 0; i < e/3; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        grupos[i].push_back(a);
        grupos[i].push_back(b);
        grupos[i].push_back(c);
    }

    int casos = validarGrupos(grupos, msmGrupo, difGrupo, e);

    cout << casos;
}