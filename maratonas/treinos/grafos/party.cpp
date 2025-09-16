#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    int n;
    vector<int> v(n, -1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<vector<int>> grid;
    for (int i = 0; i < n; i++) {
        if (v[i] == -1) {
            vector<int> v2;
            v2.push_back(-1);
            grid.push_back(v2);
        }
    }

    for (int i = 0; i < n; i++) {

    }
}