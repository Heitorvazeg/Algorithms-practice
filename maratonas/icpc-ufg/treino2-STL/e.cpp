#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    for (int j = 0; j < n; j++) {
        string s;
        getline(cin, s);

        stack<char> pilha;
        unordered_map<char, char> map;
        map[')'] = '(';
        map[']'] = '[';

        bool valid = true;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(' || s[i] == '[') {
                pilha.push(s[i]);

            } else {
                if (!pilha.empty()) {
                    char c = pilha.top();
                    pilha.pop();

                    if (map[s[i]] != c) {
                        valid = false;
                        break;
                    }
                } else {
                    valid = false;
                    break; 
                }
            }
        }
        if (valid && pilha.empty()) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
}