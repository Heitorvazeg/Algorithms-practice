// Implementação de Union-Find para ver qtd de elementos em um conjunto

#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> parents;
unordered_map<int, int> count1;

int findComp(int x) {
    if (parents[x] != x) {
        parents[x] = findComp(parents[x]);
    }

    return parents[x];
}

void unionF(int a, int b) {
    int cA = findComp(a);
    int cB = findComp(b);

    parents[cB] = cA;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        parents.clear();
        count1.clear();
        int n, m;
        cin >> n >> m;

        for (int j = 0; j < n; j++) {
            parents[j+1] = j+1;
        }

        for (int j = 0; j < m; j++) {
            int p1, p2;
            cin >> p1 >> p2;

            if (findComp(p1) == findComp(p2)) continue;
            unionF(p1, p2);
        }
        
        int max = 0;
        for (auto it : parents) {
            int aux = findComp(it.second);
            if (!count1.count(aux)) count1[aux] = 1;
            else count1[aux]++;
        }

        for (auto it : count1) {
            if (it.second > max) max = it.second; 
        }

        cout << max << "\n";
    }
}