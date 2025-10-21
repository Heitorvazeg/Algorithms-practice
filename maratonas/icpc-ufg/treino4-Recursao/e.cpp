#include <bits/stdc++.h>

using namespace std;

void hanoi(int n, int origem, int destino, int aux) {
    if (n == 1) {
        cout << origem << " " << destino << "\n";
        return;
    }

    hanoi(n-1, origem, aux, destino);
    cout << origem << " " << destino << "\n";
    hanoi(n-1, aux, destino, origem);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int count = (1 << n) - 1;
    cout << count;

    hanoi(n, 1, 3, 2);
}