#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string palavra, anagrama;
    getline(cin, palavra);
    getline(cin, anagrama);

    map<char, int> freq;
    int size = palavra.size();

    for (int i = 0; i < size; i++) {
        freq[palavra[i]]++;
    }

    int count = 0;
    for (int i = 0; i < size; i++) {
        if (freq.count(anagrama[i])) {
            count++;
        }
        if (anagrama[i] == '*') {
            count++;
        }
    }

    if (count == size) {
        cout << "S";

    } else {
        cout << "N";
    }
}