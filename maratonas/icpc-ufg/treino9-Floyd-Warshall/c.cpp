#include <bits/stdc++.h>

using namespace std;

const long long INF = numeric_limits<long long>::max()/4;

void Floyd(vector<vector<long long>>& dist, int n) {
    for (int k = 0; k < n; k++) {
        dist[k][k] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        int siz = s.size();
        
        vector<string> grid(siz);
        grid[0] = s;
 
        for (int j = 1; j < siz; j++) {
            string s;
            cin >> s;
            grid[j] = s;
        }

        vector<vector<long long>> dist(siz+1, vector<long long>(siz+1, INF));
        for (int j = 0; j < siz; j++) {
            for (int k = 0; k < siz; k++) {
                if (j == k) dist[j][k] = 0;
                if (grid[j][k] == 'Y') {
                    dist[j][k] = 1;
                }
            }
        }

        Floyd(dist, siz);

        pair<int, int> p;
        p.first = 0;
        for (int j = 0; j < siz; j++) {
            int ct = 0;
            for (int k = 0; k < siz; k++) {
                if (dist[j][k] == 2) ct++;
            }

            if (ct > p.first) {
                p.first = ct;
                p.second = j;
            }
        }
        cout << p.second << " " << p.first << "\n";
    }
}