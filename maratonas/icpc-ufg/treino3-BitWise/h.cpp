#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull; 

__uint128_t countD(ull num) {
    __uint128_t count = 0;

    for (int i = 0; i <= 53; i++) {
        ull aux = (1ull << (i+1));
        ull aux2 = (1ull << i);

        ull vezes = (num+1) / aux;

        ull count2 = 0;

        count2 += (vezes * aux2);

        ull pos = (num+1)%aux;

        if (pos > aux2) {
            count += (pos - aux2);
        }

        count += count2;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ull a, b;
    while (cin >> a >> b) {
        __uint128_t zeroAteA = countD(a-1);
        __uint128_t zeroAteB = countD(b);

        ull ans = zeroAteB - zeroAteA;

        cout << ans << "\n";
    }
}