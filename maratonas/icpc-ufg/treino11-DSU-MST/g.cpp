#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> parent;

int find_f(int a) {
    if (a != parent[a]) {
        parent[a] = find_f(parent[a]);
    }

    return parent[a];
}

void union_f(int a, int b, vector<long long>& rank) {
    int dA = find_f(a);
    int dB = find_f(b);

    if (dA == dB) return;

    if (rank[dA] > rank[dB]) {
        parent[dB] = dA;

    } else if (rank[dA] < rank[dB]){
        parent[dA] = dB;

    } else if (rank[dA] == rank[dB]) {
        parent[dB] = dA;
        rank[dA]++;
    }
}

void make_set(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    pair<long long, long long> origin;
    pair<long long, long long> dest;

    cin >> origin.first >> origin.second >> dest.first >> dest.second;
    vector<tuple<long long, long long, long long>> circles(n);
    vector<long long> circleOr;
    vector<long long> circleDes;

    for (int i = 0; i < n; i++) {
        long long x, y, r;
        cin >> x >> y >> r;
        circles[i] = make_tuple(x, y, r);
    }

    for (int i = 0; i < n; i++) {
        auto [x, y, r] = circles[i];
        auto distaOr = hypot((long double)x - (long double)origin.first, (long double)y - (long double)origin.second);
        auto distaDes = hypot((long double)x - (long double)dest.first, (long double)y - (long double)dest.second);

        if (fabs(distaOr - (long double)r) <= 1e-9) circleOr.push_back(i);
        if (fabs(distaDes - (long double)r) <= 1e-9) circleDes.push_back(i);
    }

    make_set(n);
    vector<long long> rank(n, 0);
    for (int i = 0; i < n; i++) {
        auto [x1, y1, r1] = circles[i];
        for (int j = i+1; j < n; j++) {
            auto [x2, y2, r2] = circles[j];
            auto dis = hypot((long double)x1 - (long double)x2, (long double)y1 - (long double)y2);
            if (fabs((long double)r1 - (long double)r2) <= dis + 1e-9 && dis <= (long double)r1 + (long double)r2 + 1e-9) {
                if (find_f(i) != find_f(j)) {
                    union_f(i, j, rank);
                }
            }
        }
    }
    
    bool valid = false;
    for (int i = 0; i < (int)circleOr.size(); i++) {
        for (int j = 0; j < (int)circleDes.size(); j++) {
            if (find_f(circleOr[i]) == find_f(circleDes[j])) {
                valid = true;
            }
        }
    }
    
    if (valid) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}