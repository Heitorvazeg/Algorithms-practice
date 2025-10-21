#include <bits/stdc++.h>

/* Tirar xor seguidos de 0 até um número segue uma sequência:
    n, 1, n+1, 0. Logo, tirar o resto por 4 acha a posição da sequência.
    
    tirar xor de 2 numeros iguais sempre dá 0.
    Então, se tirar xor de todas a sequencia de 0 até b, com o xor de toda
    a sequência de 0 até a, vai eliminar os xors repetidos que estão fora do 
    intervalo.*/

using namespace std;

unsigned long long get_xor_x(unsigned long long x) {
    if (x < 0) return 0;
    unsigned long long resto = x % 4;
    if (resto == 0) {
        return x;

    } else if (resto == 1) {
        return 1;

    } else if (resto == 2) {
        return x+1;

    } else {
        return 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    unsigned long long a, b;
    cin >> a >> b;

    unsigned long long ans = get_xor_x(b)^get_xor_x(a-1);

    cout << ans;
}