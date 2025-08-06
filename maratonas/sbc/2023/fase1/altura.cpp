#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, h;

    cin >> n >> h;

    int c = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x <= h) c++;
    }

    cout << c << "\n";
}