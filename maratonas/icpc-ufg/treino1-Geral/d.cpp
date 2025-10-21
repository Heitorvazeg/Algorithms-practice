#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int w;
    cin >> w;

    if (w == 2) {
        cout << "NO";
        return 0;
    }

    if (w % 2 == 0) {
        cout << "YES";

    } else {
        cout << "NO";
    }
}