#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, p;
    cin >> n >> m >> p;
    cin.ignore();

    int count = 0;
    vector<vector<int>> matriz(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            count++;
            matriz[i][j] = count;
        }
    }

    for (int i = 0; i < p; i++) {
        string ent;
        getline(cin, ent);
        
        if (ent[0] == 'C') {
            int a = ent[2] - '0';
            int b = ent[4] - '0';
            a--;
            b--;

            for (int j = 0; j < n; j++) {
                swap(matriz[j][a], matriz[j][b]);
            }

        } else {
            int a = ent[2] - '0';
            int b = ent[4] - '0';
            a--;
            b--;

            for (int j = 0; j < m; j++) {
                swap(matriz[a][j], matriz[b][j]);
            }
        }
}

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}