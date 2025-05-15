/*Graph:
Uma agregação não linear de nós e edges(arestas). O nó contém um tipo de dado, e o edge é a conexão entre dois nós.
Undirect Graph: Conexões com adjacência. Conexões proximas com edge.
Direct Graph: As edges conectam nós em uma só direção; adjacencia apenas de ida.
Adjacency Matrix: Uma forma de representar e com essa matrix: Uma tabela em que cada linha representa
um nó, e as colunas, que são os outros nós, recebem dados como 0 ou 1 para dizer se existe edges entre
esses nós. O(1) em time, O(v^2) em espaço alocado.
Adjacency List: Um array de linkedLists; cada nó seria uma linkedlist armazenada e que mostra as 
suas adjacencias.
O(v) em time, O(V + E) em espaço.*/

#include <iostream>
#include <vector>

int nodes = 5;

int main() {
}

void AdjacencyMatrix()  {
    std::vector<std::vector<int>> graph(nodes, std::vector<int>(nodes, 0)); /*Array 2d; aloca espaço para o vetor
    1 e o vetor 2*/

    graph[0][1] = 1; /*Quando é undirect, precisa colocar a direção para os dois nós: 0,1; 1,0.*/
    graph[1][0] = 1;

    graph[0][2] = 1;
    graph[2][0] = 1;

    graph[1][3] = 1;
    graph[3][1] = 1;

    graph[2][3] = 1;
    graph[3][2] = 1;

    for (int i = 0; i < nodes; i++) {
        for (int j = 0;  j < nodes; j++)  {
            std::cout << graph[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void AdjacencyList() {
};

class GraphM {
    private:

    int node;
    bool direct;
    std::vector<std::vector<int>> matriz;

    public:

    GraphM(int nodes, bool ehdirect = false) {
        node = nodes;
        direct = ehdirect;
        matriz = std::vector<std::vector<int>>(node, std::vector<int>(node, 0));
    }

    /*Metodos aqui; empty, add, remove...*/
    void add(int u, int v, int peso = 1) {
        matriz[u][v] = peso;
        if (!direct) {
            matriz[v][u] = peso;
        }
    }

    void remove(int u, int v, int peso = 0) {
        matriz[u][v] = peso;
        if (!direct) { /*Caso seja undirect, remove nos dois nós*/
            matriz[v][u] = peso;
        }
    }

    bool edgeExist(int u, int v) {
        return matriz[u][v] != 0;
    }
};


struct Node {
    int destino;
    Node* next;

    Node(int d) {
        destino = d;
        next = nullptr;
    }
};

void inserirNoInicio(Node*& head, int valor) {
    Node* novoNode = new Node(valor);
    novoNode -> next = head;
    head = novoNode; /*Refere a si mesmo pq é o Head, o primeiro.*/
};

void inserirNoMeio(Node*& head, int valor, int posicao) {
    if (posicao == 0) {
        inserirNoInicio(head, valor);
        return;
    }

    Node* novo = new Node(valor); /*Novo possui o endereço de memoria no novo nó criado*/
    Node* atual = head; /*vai percorrer a lista; começa apontando ao head*/

    for (int i = 0; i < posicao - 1 && atual != nullptr; i++) {
        atual = atual->next; /*move pela lista usando o next dos nós*/
    }

    if (atual != nullptr) { /*Nao pode ser o ultimo pq ele aponta para nullptr*/
        novo -> next = atual->next; /*O novo nó pega o ponteiro do anterior*/
        atual -> next = novo; /*O anterior recebe o ponteiro para o novo*/
    }
}