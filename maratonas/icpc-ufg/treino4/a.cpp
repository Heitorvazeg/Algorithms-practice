#include <bits/stdc++.h>

using namespace std;

void weird(long long n) {
    if (n == 1) return;

    if ((n & 1) == 1) {
        cout << (n*3)+1 << " ";
        weird((n*3)+1);

    } else {
        cout << n/2 << " ";
        weird(n/2);
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    cout << n << " ";
    weird(n);
}