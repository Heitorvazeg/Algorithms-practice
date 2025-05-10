/* FILO: first in last out.
Classe pilha é intuitiva; pode adicionar ao pico e apenas retirar do pico; exemplos de 
uso se relacionam com a possibilidade de retornar um evento de cada vez: Ctrl + Z; o histórico
do Google... 
Stack/Pilha*/ 

#include <iostream>
#include <stack>

int main() {
    std::stack<int> pilha;

    pilha.push(20);
    pilha.push(30);
    pilha.push(40);

    int topo = pilha.top();
    bool yes = pilha.empty();
    int tamanho = pilha.size();

    while (!pilha.empty()) {
        std::cout << pilha.top() << std::endl;
        pilha.pop();
    }
    std::cout << "Topo: " << topo << std::endl;
    
    if (yes) {
        std::cout << "Yes" << std::endl;

    } else {
        std::cout << "No" << std::endl;
    }

    std::cout << "Tamanho: " << tamanho << std::endl;
}