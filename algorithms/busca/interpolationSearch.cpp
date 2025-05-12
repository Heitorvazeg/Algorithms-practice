/*Melhoria na busca binária. Interpolation Search.
Trabalha com adivinhações de onde o valor pode estar baseado em "probe results". Funciona em sequências
uniformes.
O(log(log n))*/

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vetor = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int high = vetor.size()-1;
    int low = 0;
    int valor;
    std::cin >> valor;

    while (valor <= vetor[high] && valor >= vetor[low] && low <= high) {
        int probe = low + (high - low) * (valor - vetor[low]) / (vetor[high] - vetor[low]);
        /*Formula para calcular a probabilidade.*/

        if (vetor[probe] == valor) {
            std::cout << probe << std::endl;
            return probe;
        }
        if (vetor[probe] < valor) {
            low = probe + 1;

        } else {
            high = probe - 1;
        }
    }
    std::cout << "Elemento nao esta no vetor" << std::endl;
    return -1;
}