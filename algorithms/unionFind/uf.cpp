/*Union Find:
Conjuntos; inicialmente cada pessoa é o próprio lider de seu conjunto. Quando dois ele-
mentos se unem eles se tornam um grupo só. Union: Une grupos. Se chamar alguém que 
pertence a um grupo, todo o grupo se junta ao outro. Find; Encontra a qual conjunto
um elemento pertence. O pai do conjunto sempre vai ter seu pai como ele mesmo. Quando
une dois conjuntos, o pai pode ser decidido aleatoriamente, ou com prioridade em size.
*/

#include <iostream>
#include <unordered_map>

std::unordered_map<int, int> parent;

int main() {
    make_set(5);
}

void make_set(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i; /*Inicia com cada um sendo seu próprio pai*/
    }
}

int Find(int element) {
    if (parent[element] == element) return element;
    return Find(parent[element]);
}

void Union(int a, int b) {
    int pA = Find(a);
    int pB = Find(b);
    parent[pB] = pA;
}

/*Compressão de caminho: Chama os filhos do conjunto direto ao pai; pega todos os
pais e aponta para o pai maximo*/

int FindPathC(int x) {
    if (parent[x] != x) {
        parent[x] = FindPathC(parent[x]);
    }
    return parent[x];
}