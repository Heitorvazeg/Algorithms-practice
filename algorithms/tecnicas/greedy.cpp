/*Greedy  Algorithm:
Como  conseguir chegar no  resultado com o menor numero possível  de recursos.
Nem sempre entrega o resultado mais otimizado.
1- Encontrar que escolhas vc tem a cada passo
2- achar a melhor escolha e perfomar isso. (Precisa ser comparavel, precisar saber como uma escolha
é melhor doq a outra)
Apenas faz oque parece melhor*/

#include <iostream>
#include <vector>

int coins() { /*Em um algoritmo de otimização de troco, sempre busca a maior moeda possivel.
    Aqui sao comparaveis em valor*/
    int nota = 25;
    std::vector<int> notas = {50, 20, 10, 5, 2}; /* de maior para menor*/

    std::cin >> nota;

    int totalM = 0;
    for (int moeda : notas) {
        if (nota >= moeda) { /* sempre  pega a maior possibilidade*/
            int qtd = nota / moeda;
            totalM += qtd;
            nota -= qtd * moeda;
        }
    }
    return totalM;
}

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxD = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > maxD) return false;
            maxD = std::max(maxD, i + nums[i]);
        }

        return true;
    }
};

