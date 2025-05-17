/*Trees:
Estruturas de dados nao linear onde os nós são organizados em hierarquia. É feito de 
nós e arestas(nodes and edges). Edge é a relação entre 2 nodes.
Exemplos: Arvores genealogicas, HTML DOM, databases, fileExplorer...
Topo: Root, raiz. Não tem edges vindo a ele, apenas saindo.
Bottom: Leafs, folhas. São os últimos nós; não saem edges das folhas, apenas chegam.
Mid: Branch nodes. Nós meio termo; edges entram e saem.
Relação Parent, child. Semelhante ao HTML DOM. 
O tamanho é a quantidade de nós. A profundidade é a qtd de edges abaixo da raiz.
A altura é o contrario.

Basicamente um tipo de grafo.
Árvore binária recebe os menores valores na esquerda e os maiores na direita.*/

#include <iostream>
#include <vector>

using namespace std;

/*Implementação basica de arvore binária*/

struct Node {
    int value;
    Node* esquerda;
    Node* direita;

    Node(int valor) {
        value = valor;
        esquerda = nullptr;
        direita = nullptr;
    }
};

void traverseTree(Node* raiz);
Node* inserir(Node* raiz, int val);

Node* inserir(Node* raiz, int val) {
    if (raiz == nullptr) return new Node(val);
    if (val > raiz -> value) raiz->direita = inserir(raiz -> direita, val);
    else raiz->esquerda = inserir(raiz->esquerda, val);
    return raiz;
}

void traverseTree(Node* raiz) {
    if (raiz == nullptr) return;
    traverseTree(raiz->esquerda);
    cout << raiz->value << " ";
    traverseTree(raiz->direita);
}

int main() {
    int nodes = 6;
    vector<vector<int>> matriz(nodes, vector<int>(nodes));

    matriz[0][1] = 1;
    matriz[0][2] = 1;

    matriz[1][3] = 1;
    matriz[2][4] = 1;

    matriz[4][5] = 1;

    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    Node* raiz = new Node(8);
    inserir(raiz, 5);
    inserir(raiz, 9);
    inserir(raiz, 3);
    inserir(raiz, 2);

    traverseTree(raiz);
}