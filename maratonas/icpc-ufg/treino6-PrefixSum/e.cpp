#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, q;
        cin >> n >> q;

        vector<long long> hs(n, 0);
        for (int j = 0; j < n; j++) {
            cin >> hs[j];
        }
        vector<long long> hsPref(n, 0);
        vector<long long> maiorHsPref(n, 0);
        maiorHsPref[0] = hs[0];
        hsPref[0] = hs[0];
        for (int j = 1; j < n; j++) {
            hsPref[j] = hsPref[j-1] + hs[j];
            maiorHsPref[j] = max(hs[j], maiorHsPref[j-1]);
        }

        sort(hs.begin(), hs.end());
        for (int j = 0; j < q; j++) {
            long long ques;
            cin >> ques;
            
            if (ques == 0) {cout << 0 << " "; continue;}
            
            auto it = upper_bound(maiorHsPref.begin(), maiorHsPref.end(), ques);
            int pos = int(it - maiorHsPref.begin())-1;

            if (pos >= 0) cout << hsPref[pos] << " ";
            else cout << 0 << " ";
        }

        cout << "\n";
    }
}