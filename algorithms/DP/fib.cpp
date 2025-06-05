#include <bits/stdc++.h>

using namespace std;

int memo[1000];

int main() {
    memset(memo, -1, sizeof(memo));
}

int fibMemoization(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = fibMemoization(n-1) + fibMemoization(n-2);
}

int fibTabulation(int n) {
    if (n <= 1) return n;
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}