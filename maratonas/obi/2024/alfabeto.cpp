#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k, n;
    cin >> k >> n;
    cin.ignore();

    string letters;
    getline(cin, letters);

    unordered_map<char, int> map;
    for (int i = 0; i < k; i++) {
        map[letters[i]] = i;
    }

    string msg;
    getline(cin, msg);

    int c = 0;
    for (int i = 0; i < n; i++) {
        if (!map.count(msg[i])) {
            cout << "N";
            c++;
            break;
        }
    }

    if (c == 0) {
        cout << "S";
    }
}