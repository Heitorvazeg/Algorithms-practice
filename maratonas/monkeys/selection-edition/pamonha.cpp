#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    string s;
    getline(cin, s);

    vector<char> alfabeto = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                            'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                                'V', 'W', 'X', 'Y', 'Z'};

    string sR = s;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == ' ') {
            sR[i] = ' ';
            continue;
        }

        int ind = 0;
        for (int j = 0; j < (int)alfabeto.size(); j++) {
            if (alfabeto[j] == s[i]) ind = j;
        }
        int pos = ind+n;
        if (ind+n > 25) pos = ind+n-26;
        sR[i] = alfabeto[pos];
    }

    cout << sR;
}