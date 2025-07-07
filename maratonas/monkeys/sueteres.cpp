#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> cores(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> cores[i];
    }

    vector<int> estoque(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> estoque[i];
    }

    long long min = 10000000001;
    for (int i = 0; i < n; i++) {
        int qtd = estoque[i]/cores[i];

        if (qtd < min) {
            min = qtd;
        }
    }

    cout << min;
}