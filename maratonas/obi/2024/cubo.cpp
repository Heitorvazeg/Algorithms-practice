#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    int tres = 8;

    int dois = (n-2)*12;

    int um = ((n-2)*(n-2)) * 6;
    
    int nenhum;
    if (n > 2) {
        nenhum = (n*n*n) - tres - dois- um;

    } else {
        nenhum = 0;
    }

    cout << nenhum << "\n";
    cout << um <<  "\n";
    cout << dois << "\n";
    cout << tres << "\n"; 
}