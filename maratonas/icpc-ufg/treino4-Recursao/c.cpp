#include <bits/stdc++.h>

using namespace std;

void to3(vector<int>& vetor, int it, vector<long long> atual, vector<long long>& vetorAns) {
    if (it == -1) {
        if (!atual.empty()) {
            long long num = 0;
            for (long long x : atual) {
                num = num * (long long)10 + x;
            }

            if (num % 3 == 0) {
                vetorAns.push_back(num);
            }
        }

        return;
    }

    atual.push_back(vetor[it]);
    to3(vetor, it-1, atual, vetorAns);
    
    atual.pop_back();
    to3(vetor, it-1, atual, vetorAns);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;
    
    vector<int> v;
    while (n > 0) {
        int num = n % 10;
        v.push_back(num);
        n = n / 10;
    }
    int s1 = v.size();

    vector<long long> vetorAns;
    vector<long long> atual;
    to3(v, s1-1, atual, vetorAns);
    
    int ans;
    vector<int> numF;
    if (vetorAns.empty()) ans = -1;
    else {
        long long aux = vetorAns[0];
        while (aux > 0) {
            int aux2 = n % 10;
            numF.push_back(aux2);
            aux = aux / (long long)10;
        }

        ans = s1 - (int)numF.size();
    }

    cout << ans;
}