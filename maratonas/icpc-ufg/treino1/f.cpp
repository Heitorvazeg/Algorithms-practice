#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n, k;
    cin >> n >> k;

    vector<long long> v;

    if (k > (n+1)/2) {
        long long num = k - (n+1)/2;
        cout << num*2;

    } else {
        cout << k + (k-1);
    }
}