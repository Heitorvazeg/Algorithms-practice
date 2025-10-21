#include <bits/stdc++.h>

using namespace std;

/* Pode-se pensar nos números binários como uma soma de potências de 2.
    Se faz parte da sequência da potência de 2, como 4, 8, 16..., o binário
    sempre terá apenas um 1. Se não faz parte, é preciso ligar outros 1s para achar
    o número. As bacterias representam isso, a qtd de 1s ligados é quao fora da sequência
    da potência de 2 o número está. Logo, só contar os 1s.*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    unsigned int x;
    cin >> x;

    unsigned int count = 0;

    for (int i = 0; i <= 31; i++) {
        if ((x & (1<<i)) >= 1) {
            count++;
        }
    }

    cout << count;
}