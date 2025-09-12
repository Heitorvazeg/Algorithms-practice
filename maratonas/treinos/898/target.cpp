#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;


    for (int l = 0; l < n; l++) {
        vector<vector<char>> grid(10, vector<char>(10));
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                cin >> grid[i][j];
            }
        }

        int pontos = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (grid[i][j] == 'X') {
                    int dTopo = i;
                    int dBaixo = 10-i-1;
                    int dEsquerda = j;
                    int dDireita = 10-j-1;

                    int minDist = min({dTopo, dBaixo, dEsquerda, dDireita});
                    pontos += minDist+1;
                }
            }
        }
        cout << pontos << "\n";
    }
}