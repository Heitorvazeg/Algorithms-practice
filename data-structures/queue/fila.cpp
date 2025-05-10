/* FIFO: first in first out.  Linear.
Classe fila é intuitiva; quem chegar primeiro é servido primeiro; head e o primeiro, tail o último; se tiver apenas
um, será ambos, head e tail. Exemplos: Keyboard Buffers, quando vc escreve ele espera em fila para manter a ordem.
LinkedLists, PriorityQueues, Breath-First Search.
Queue/Fila*/ 

#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> fila;

    fila.push(1);
    fila.push(2);
    fila.push(3);
    fila.push(4);

    fila.pop(); /* Tira o primeiro*/

    int head = fila.front();
    int tail = fila.back();
    bool yes = fila.empty();
    int tamanho = fila.size();

    cout << head << endl;
    cout << tail << endl;
    
    if (yes) {
        cout << "Yes" << endl;

    } else {
        cout << "No" << endl;
    }

    cout << tamanho << endl;

    while (!fila.empty()) {
        int head_2 = fila.front();
        cout << head_2 << endl;
        fila.pop();
    }
}