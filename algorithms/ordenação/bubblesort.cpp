/*Algoritmo de ordenação que organiza um array; confere 2 elementos adjcentes e vê quem é maior, se for, troca
os elementos com a ajuda de uma variavel auxiliar. Bubble pq os maiores valores sao empurrados ao final do 
array como bolhas. Precisa de n-1 repetições para ordenar o array. O(n^2); nao é mt eficiente.*/

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vetor = {8, 5, 3, 0, 6, 7, 2, 1};

    for (int i = 0; i < vetor.size(); i++) {
        for (int j = 0; j < vetor.size()-1; j++) {
            if (vetor[j] > vetor[j+1]) {
                int auxiliar = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = auxiliar;
            }
        }
    }
    for (int k = 0; k < vetor.size(); k++) {
        std::cout << vetor[k] << std::endl;
    }
}