#include <bits/stdc++.h>

using namespace std;

/* Sequência de xor segue o padrão:
a, b, a^b, a, b, a^b. Pois, em a^b^b, b^b dá 0. E a^0 é a.*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        long long a, b, n;
        cin >> a >> b >> n;

        if (n % 3 == 0) {
            cout << a << "\n";
        } else if (n % 3 == 1) {
            cout << b << "\n";
        } else {
            long long ans = a^b;
            cout << ans << "\n";
        }
    }
}