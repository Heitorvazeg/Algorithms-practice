#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long num;
    cin >> num;

    vector<long long> sums;
    for (int i = 0; ; i++) {
        if (pow(2, i) > num) break;
        sums.push_back(pow(2, i));
    }

    int count = 0;
    int it = sums.size()-1;
    while (num > 0) {
        if (it == -1) break;
        if (num >= sums[it]) {
            num -= sums[it];
            it--;
            count++;
            continue;
        }
        it--;
    }
    cout << count;
}