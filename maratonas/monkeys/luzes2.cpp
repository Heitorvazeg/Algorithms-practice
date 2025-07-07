#include <bits/stdc++.h>

using namespace std;

string acharLuz(int s) {
    vector<string> a;

    a.push_back("A");
    a.push_back("V");

    while((int)a.back().size() < s) {
        a.push_back(a[a.size()-1] + a[a.size()-2]);
    }

    return a.back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string reversa;
    getline(cin, reversa);
    int s = reversa.size();

    string normal = acharLuz(s);

    cout << normal;
}