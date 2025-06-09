#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int e, d;
    cin >> e >> d;

    if (e > d) {
        cout << e+d;

    } else {
        cout << 2*(d-e);
    }

    return 0;
}