#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int max = 0;
    int it = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > max) {
            max = v[i];
            it = i;
        }
    }
    v[it] = v[it]/2;

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
    }

    cout << sum;
}