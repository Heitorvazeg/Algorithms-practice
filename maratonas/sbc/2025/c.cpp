#include <bits/stdc++.h>

using namespace std;

int count1 = 0;

void cluts(int num) {
    if (num == 1) {
        return;
    }

    if ((num & 1) == 1) {
        num = (num << 1)^num^1;
        count1++;
        cluts(num);

    } else if ((num & 1) == 0) {
        num = (num >> 1);
        count1++;
        cluts(num);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n+1, 0);
    for (int i = 0; i <= n; i++) {
        cin >> v[i];
    }

    int num = 0;
    for (int i = 0; i <= n; i++) {
        num = (num << 1)^v[i];
    }

    cluts(num);

    cout << count1;
}