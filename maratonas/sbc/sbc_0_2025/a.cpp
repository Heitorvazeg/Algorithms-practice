#include <bits/stdc++.h>

using namespace std;

int main() {
    int c;
    int g;

    cin >> c;
    cin >> g;

    if (c == 1) {
        cout << "vivo e morto";

    } else {
        if (c == 0) {
            if (g == 0) {
                cout << "morto";

            } else {
                cout << "vivo";
            }
        }
    }
}