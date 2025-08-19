#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int duplas;
        cin >> duplas;

        vector<int> esforço(duplas*2, 0);
        for (int j = 0; j < duplas*2; j++) {
            cin >> esforço[j];
        }

        int it = (int)esforço.size()-1;
        sort(esforço.begin(), esforço.end());

        vector<long long> duplasVal(duplas);
        for (int j = 0; j < (int)esforço.size()/2; j++) {
            duplasVal[j] = esforço[it]+esforço[j];
            it--;
        }

        if ((int)duplasVal.size() == 1) {
            cout << duplasVal[0] << " " << duplasVal[0] << "\n";

        } else {
            long long maxiI = *max_element(duplasVal.begin(), duplasVal.end());
            long long minI = *min_element(duplasVal.begin(), duplasVal.end());

            cout << minI << " " << maxiI << "\n";
        }
    }
}