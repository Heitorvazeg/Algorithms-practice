#include <bits/stdc++.h>

using namespace std;

vector<int> make_set(int n) {
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        v[i] = i;
    }
    return v;
}

int find_comp(vector<int>& v, int i) {
    if (v[i] != i) {
        v[i] = find_comp(v, v[i]);
    }
    return v[i];
}

void unionS(vector<int>& v, int a, int b) {
    int pA = find_comp(v, a);
    int pB = find_comp(v, b);

    v[pB] = pA;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;

    cin >> n >> m >> k;


    vector<int> set = make_set(n);
    
}