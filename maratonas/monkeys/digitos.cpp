#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    long long sum = pow(b, 1);
    int it = 2;
    while (sum <= a) {
        sum = pow(b, it);
        it++;
    }
    cout << it-1;
}