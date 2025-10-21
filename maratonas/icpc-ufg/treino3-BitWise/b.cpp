#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    unsigned int q;
    cin >> q;

    for (unsigned int i = 0; i < q; i++) {
        unsigned int x;
        cin >> x;

        unsigned int ans = ~x;
        
        cout << ans << "\n";
    }
}