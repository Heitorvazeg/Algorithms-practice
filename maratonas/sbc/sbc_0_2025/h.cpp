#include <bits/stdc++.h>

using namespace std;

bool ehPali(long long x) {
    long long original = x;
    long long reversed = 0;

    while (x > 0) {
        reversed <<= 1;
        reversed |= (x & 1);
        x >>= 1;
    }

    return original == reversed;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long x;
    cin >> x;

    for (long long i = x; i >= 0; i--) {
        if (ehPali(x)) {
            cout << x;
            break;
        }
    }
}