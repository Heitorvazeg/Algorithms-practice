/*Backtracking:
Quando entrar em uma decisão "errada", você volta e procura outro caminho.
Muito associado a recursão.
O código mantém as posições do inicio até a atual e as posições já visitadas.
Lógica de pilha para retornar. Dfs é diferente de backtrancking, dfs está apenas
explorando, o objetivo é ver todas as possibilidades.

Padrão backtracking:
    se condição de parada:
        registrar solução
        return
    
    para cada escolha possível:
        fazer escolha
        recursão com a escolha()
        desfazer escolha, senao for.
*/

#include <iostream>
#include <vector>

int main() {

}

void gerarSubconjunto(std::vector<int>& nums, int i, std::vector<int>& atual) {

}