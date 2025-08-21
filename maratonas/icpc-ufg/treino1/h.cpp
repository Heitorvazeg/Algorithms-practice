#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int num = 0;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;

        num += (r - l + 1);
    }
    cout << num;
}