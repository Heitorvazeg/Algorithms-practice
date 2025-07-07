#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> listarVizinhos(int xV, int yV, int n, int m);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> matriz(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matriz[i][j];
        }
    }

    vector<vector<int>> matrizR(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fila;
            unordered_map<string, bool> visited;

            fila.push({i, j});
            auto [u, dw] = fila.top();
            string chave = "1" + to_string(u) + to_string(dw);
            visited[chave] = true;

            int valorR = matriz[u][dw];
            pair<int, int> origem = {i, j};

            while(!fila.empty()) {
                auto [a, b] = fila.top();
                if (matriz[a][b] <= valorR) {
                    if (a == origem.first && b == origem.second) {
                        valorR -= matriz[a][b];
                    }
                    valorR += matriz[a][b];

                } else {
                    fila.pop();
                    continue;
                }

                fila.pop();

                vector<pair<int, int>> vizinhos = listarVizinhos(a, b, n, m);
                int s = vizinhos.size();
                for (int k = 0; k < s; k++) {
                    auto [c, d] = vizinhos[k];
                    string chaveV = "1" + to_string(c) + to_string(d);
                    
                    if (!visited[chaveV]) {
                        fila.push({c, d});
                        visited[chaveV] = true;
                    }
                }
            }
            matrizR[i][j] = valorR;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrizR[i][j] << " ";
        }
        cout << "\n";
    }
}

vector<pair<int, int>> listarVizinhos(int xV, int yV, int n, int m) {
    vector<pair<int, int>> vizinhos;

    vector<int> x = {-1, 0, 0, 1};
    vector<int> y = {0, -1, 1, 0};
    for (int i = 0; i < 4; i++) {
        int nx = xV + x[i];
        int ny = yV + y[i];

        if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
            vizinhos.push_back({nx, ny});
        }
    }

    return vizinhos;
}