/*Linked lists:
Arrays normais não são tao poderosos quando trata-se de mudar algum elemento interno, justamente por 
terem memória contínua. Se tiver um array de tamanho[10] e quiser alterar o 3, precisa copiar todos os dados e 
passar para frente para acomodar outro. E se à frente já tiver dados? Complicado de se lidar com memória...
Linked list resolve esse problema; cada linkedlist recebe um dado para armazenar e um endereço para o proximo
elemento. Não sao continuos e nao possuem index. Se o valor da tail for null, é o fim da lista. Se quiser mudar,
basta colocar no anteior o endereço do atual, e no atual colocar o antigo endereço do anterior.
Um problema e em relação a busca, pq vc precisa andar por toda a lista por nao ter index.
Usos: GPS navigation. Spotify: Playlist de música linkada.*/

/*Doubly linked lists:
armazenam 2 endereços de memoria em um elemento. O primeiro tem o esquerdo nulo e o ultimo tem o direito nulo.
Cada elemento sabe onde está o elemento(node) passado e o da frente.*/

#include <iostream>
#include <list>

int main() {
    std::list<int> linkedList;

    linkedList.push_back(10);
    linkedList.push_front(20);
    linkedList.push_back(30);

    for (auto it = linkedList.begin(); it != linkedList.end(); ++it) {
        if (*it == 30) {
            linkedList.insert(it, 99);
        } /*it begin começa no primeiro node, it != .end() continua o loop até o último*/
    }

    for (auto it = linkedList.begin(); it != linkedList.end(); ++it) { /*iterador: usado para percorrer a lista, atua como ponteiro.*/
        std::cout << *it << std::endl;
    }
}