/*FIFO.
Filas com prioridade. Coloca primeiro a fila em ordem de prioridade e depois serve os primeiros. 
É importante para situações em que a partir de determinada prioridade vc faz determinada coisa com o valor.
Exemplo: GPAs, ordena a fila crescentemente, e quem tiver primeiro (menor nota) recebe determinada "punição".*/

#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> pq; /*Prioridade padrão: Max-Heap; prioridade é o maior valor*/

    pq.push(5);
    pq.push(1);
    pq.push(20);

    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
}
/*nao possui os metodos normais da queue: Front, back...
mas possui o emplace(), que constroi elementos diretamente dentro da PQ; usado em estruturas mais complexas,
tipo pares.*/