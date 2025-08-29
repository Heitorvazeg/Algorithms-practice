#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 

    int n;
    cin >> n;

    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> aux = v;
    sort(v.begin(), v.end(), std::greater<int>());


    int x;
    x = v[0];
    int y = v[1];

    for (int i = 0; i < n; i++) {
        if(x == y) cout << x << '\n';
        else if(aux[i] == x) cout << y << '\n';
        else cout << x << '\n';
    }
}