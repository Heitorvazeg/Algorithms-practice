/*Outro agoritmo de ordenação. Ele percorre o array várias vezes, sempre descobrindo qual é o menor valor e atri-
buindo a uma variavel min; quando acaba a iteração, ele troca o primeiro valor com o minimo, mas pra isso precisa
de um auxiliar para gravar o primeiro valor. O(n^2) não é tão eficiente. */

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vetor = {3, 8, 7, 5, 1, 0, 9, 6, 2, 4};

    for (int i = 0; i < vetor.size()-1; i++) {
        int min = i; /*Min = i justamente pra fazer as trocas apenas com os indexs*/
        for (int j = i+1; j < vetor.size(); j++){
            if (vetor[min] > vetor[j]) {
                min = j;
            }
        }
        int temp = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = temp;
    }

    for (int k = 0; k < vetor.size(); k++) {
        std::cout << vetor[k] << std::endl;
    }
    
    return 0;
}