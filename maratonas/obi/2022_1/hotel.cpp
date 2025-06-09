#include <bits/stdc++.h>

using namespace std;

int calcularDiaria(int diaEntrada, int A, int Diaria);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int d, a;

    cin >> d >> a;

    int dia;

    cin >> dia;

    int resultado = calcularDiaria(dia, a, d);
    cout << resultado;
}

int calcularDiaria(int diaEntrada, int A, int Diaria) {
    int resultado;
    if (diaEntrada >= 15) {
        int ARe = 14*A;
        int resultado = (31-diaEntrada+1)*(Diaria+ARe);
        return resultado;
    }

    int ARe = (diaEntrada-1)*A;

    resultado = (31-diaEntrada+1)*(ARe + Diaria);
    return resultado;
}