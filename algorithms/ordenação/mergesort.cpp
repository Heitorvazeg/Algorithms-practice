/*Merge Sort:
Divide and Conquer algoritmo. Função recursiva (chama ela em si mesma).
Divide o array com o MergeSort várias vezes até sobrar 1 elemento em cada array. Depois, 
Merge pega os subarrays e os coloca nos antigos arrays, mas em ordem, até sobrar apenas 1, ordenado.
Quando divide o array em vários, pega primeiro o lado esquerdo e faz td, e dps pega o direito e faz td. Segura
até o último, onde pega os 2 últimos arrays ordenados e ordena. O(n log n): Mais rápido do que selection e 
bubble. Usa mais espaço de memória.*/

#include <iostream>
#include <vector>

std::vector<int> mergeSort(std::vector<int> vetor);
void merge(std::vector<int>& vetorEsquer, std::vector<int>& vetorDirei, std::vector<int>& vetor);

int main() {
    std::vector<int> vetor = {2, 4, 9, 7, 5, 3, 1, 6, 8};
    vetor = mergeSort(vetor);

    for (int i = 0; i < vetor.size(); i++) {
        std::cout << vetor[i] << " ";
    }
}

std::vector<int> mergeSort(std::vector<int> vetor) {
    int len = vetor.size();

    if (len <= 1) return vetor;

    int mid = len / 2;
    std::vector<int> left(vetor.begin(), vetor.begin() + mid);
    std::vector<int> right(vetor.begin()  + mid, vetor.end());

    left = mergeSort(left); /* recursão */
    right = mergeSort(right);
    merge(left, right, vetor);
    return vetor;
}

void merge(std::vector<int>& vetorEsquer, std::vector<int>& vetorDirei, std::vector<int>& vetor) {
    int leftSize = vetor.size() / 2;
    int rightSize = vetor.size() - leftSize;

    int i = 0, l = 0, r = 0;

    while (l < leftSize && r < rightSize) {
        if (vetorEsquer[l] < vetorDirei[r]) {
            vetor[i] = vetorEsquer[l];
            i++;
            l++;

        } else {
            vetor[i] = vetorDirei[r];
            r++;
            i++;
        }
    }

    while (l < leftSize) {
        vetor[i] = vetorEsquer[l];
        i++;
        l++;
    }
    while (r < rightSize) {
        vetor[i] = vetorDirei[r];
        r++;
        i++;
    }
}