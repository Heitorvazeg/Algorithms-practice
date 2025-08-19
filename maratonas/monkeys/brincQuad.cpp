#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    if (n%2 != 0) {
        cout << "Aninha eh perdedora";
        return 0;
    }

    int c = 0;
    int d = 0;
    vector<int> vR;
    vR.push_back(v[0]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int)vR.size(); j++) {
            if (i == 0) break;
            float qd = sqrt(v[i]+vR[j]);
            if (qd * qd == v[i] + vR[j]) {
                vR.erase(vR.begin() + j);
                d++;

            } else {
                vR.push_back(v[i]);
                c++;
            }
        }
    }

    if (c == d) {
        cout << "Aninha eh vencedora";

    } else {
        cout << "Aninha eh perdedora";
    }
}