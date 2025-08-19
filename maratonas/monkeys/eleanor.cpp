#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, x1, x2;
        cin >> n >> x1 >> x2;

        int p = 0;
        int im = 0;

        if (x1%2 == 0) p++;
        if (x1%2 != 0) im++;
        
        if (x2%2 == 0) p++;
        if (x2%2 != 0) im++;

        if ()

        cout << p << " " << im << "\n";
    }
}