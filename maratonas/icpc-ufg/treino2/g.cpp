#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        vector<int> v(a, 0);
        unordered_map<int, long long> map;
        for (int j = 0; j < a; j++) {
            cin >> v[j];
        }

        map[v[0] - 0] = 1;

        for (int j = 1; j < a; j++) {
            if (map.count(v[j] - j)) {
                map[v[j] - j]++;

            } else {
                map[v[j] - j] = 1;
            }
        }

        long long sum = 0;
        for (auto it : map) {
            sum += ((it.second * (it.second - 1))/2);
        }

        cout << sum << "\n";
    }
}