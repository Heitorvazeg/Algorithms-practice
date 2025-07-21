#include <bits/stdc++.h>

using namespace std;

int fib(int n, vector<int>& tab) {
    tab[0] = 1;
    tab[1] = 2;

    for (int i = 2; i < n; i++) {
        tab[i] = tab[i-1] + tab[i-2];
    }

    return tab[n-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> tab(n, 0);
    int val = fib(n, tab);

    cout << val;
}