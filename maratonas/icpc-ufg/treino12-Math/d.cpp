#include <bits/stdc++.h>

const long long moders = (long long)(1e9+7);

using namespace std;

void product(long long f[2][2], long long b[2][2]) {
    long long w = ((f[0][0]%moders * b[0][0]%moders) + (f[0][1]%moders * b[1][0]%moders))%moders;
    long long x = ((f[0][0]%moders * b[0][1]%moders) + (f[0][1]%moders * b[1][1]%moders))%moders;
    long long y = ((f[1][0]%moders * b[0][0]%moders) + (f[1][1]%moders * b[1][0]%moders))%moders;
    long long z = ((f[1][0]%moders * b[0][1]%moders) + (f[1][1]%moders* b[1][1]%moders))%moders;

    f[0][0] = w;
    f[0][1] = x;
    f[1][0] = y;
    f[1][1] = z;
}


void power(long long f[2][2], long long n) {
    if (n < 2)  return;

    long long b[2][2] = {{1, 1}, {1, 0}};

    power(f, n/2);
    product(f, f);

    if (n & 1) product(f, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    if (n == 0) {cout << 0 << "\n"; return 0;}
    long long f[2][2] = {{1, 1}, {1, 0}};

    power(f, n-1);

    cout << f[0][0] << "\n";
}