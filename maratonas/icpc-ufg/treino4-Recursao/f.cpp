#include <bits/stdc++.h>

using namespace std;

void comp(int it, vector<long long>& origem, vector<long long>& aux, long long& dif, long long& total) {
    if (it == (int)origem.size()) {
        if (aux.size() == origem.size() || aux.empty()) return;
        long long sum1 = 0;
        for (int l = 0; l < (int)aux.size(); l++) {
            sum1 += aux[l];
        }

        long long sum2 = total - sum1;

        if (abs(sum1-sum2) < dif) dif = abs(sum1-sum2);

        return;
    }

    aux.push_back(origem[it]);
    comp(it+1, origem, aux, dif, total);

    aux.pop_back();
    comp(it+1, origem, aux, dif, total);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if (n != 1) {
        vector<long long> vetor(n, 0);
        long long total = 0;
        for (int i = 0; i < n; i++) {
            cin >> vetor[i];
            total += vetor[i];
        }
        vector<long long> aux;
        long long dif = 100000000000000;
        comp(0, vetor, aux, dif, total);
        cout << dif << "\n";

    } else {
        long long a;
        cin >> a;
        cout << a << "\n";
    }
}