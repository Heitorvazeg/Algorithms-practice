#include <bits/stdc++.h>

using namespace std;

vector<int> caminho;
vector<int> ans;
bool found = false;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int src, int pai, vector<bool>& noCaminho) {
    if (found) return;
    visited[src] = true;
    caminho.push_back(src);
    noCaminho[src] = true;

    for (auto it : graph[src]) {
        if (visited[it]) {
            if (found) return;
            if (it == pai) continue;

            if (noCaminho[it]) {
                found = true;
                ans.push_back(it);
                for (int i = (int)caminho.size()-1; i >= 0; i--) {
                    ans.push_back(caminho[i]);
                    if (caminho[i] == it) break;
                }
            }

        } else {
            dfs(graph, visited, it, src, noCaminho);
        }
        
        if (found) return;
    }

    noCaminho[src] = false;
    caminho.pop_back();

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(n+1, false);
    vector<bool> noCaminho(n+1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(graph, visited, i, -1, noCaminho);
        if (found) break;
    }

    if (!found) {cout << "IMPOSSIBLE" << "\n"; return 0;} 
    cout << ans.size() << "\n";
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << " ";
    }

    cout << "\n";
}