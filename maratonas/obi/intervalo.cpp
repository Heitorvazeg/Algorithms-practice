#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> vetor(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> vetor[i];
    }

    vector<long long> prefix(n+1, 0);

    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1] + vetor[i];
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        cout << prefix[b] - prefix[a-1] << "\n";
    }
}