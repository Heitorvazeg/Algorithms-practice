#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string palavra;
    getline(cin, palavra);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        if (a == 1) {
            b--;
            int c;
            cin >> c;
            c--;
            int beleza = 0;
            
            int aux2 = 0;
            string sub = "";
            for (int j = b; j < c+1; j++) {
                sub += palavra[j];
            }

            unordered_map<char, int> map;
            for (int i = 0; i < c+1-b; i++) {
                if (!map.count(sub[i])) {
                    map[sub[i]] = i+1-aux2;

                } else {
                    aux2++;
                }
            }

            for (int j = b; j < c+1; j++) {
                if (map.count(palavra[j])) {
                    beleza += map[palavra[j]];
                }
            }
            cout << beleza << "\n";

        } else {
            char c;
            cin >> c;
            b--;

            palavra[b] = c;
        }
    }
}