/*Backtracking:
Quando entrar em uma decisão "errada", você volta e procura outro caminho.
Muito associado a recursão.
O código mantém as posições do inicio até a atual e as posições já visitadas.
Lógica de pilha para retornar. Dfs é diferente de backtrancking, dfs está apenas
explorando, o objetivo é ver todas as possibilidades.

Nao recursiva ou recursiva.

Padrão backtracking:
    se condição de parada:
        registrar solução
        return
    
        fazer escolha
        recursão com a escolha()
        desfazer escolha, senao for.
*/

#include <bits/stdc++.h>

using namespace std;

// Não recursiva
list<int> labirinto(list<int> maze[], int start, int finish) {
    // Visitados e o caminho percorrido
    unordered_set<int> visited;
    list<int> path;

    // Inicio do algoritmo; passa start para o path
    path.push_back(start); 
    int currentPoint = start;
    visited.insert(currentPoint);

    while (path.back() != finish && !path.empty()) {
        // iterador que atravessa a linked list
        list<int>::iterator it = maze[currentPoint].begin();
        bool found = false;

        // Vê se esta no final da lista
        while ((it != maze[currentPoint].end()) && !found) {

            if (!visited.count(*it)) {
                found = true;

            } else {
                it++;
            }
        }
        // Se achou algum vizinho passa ele ao path
        if (found) {
            path.push_back(*it);
            visited.insert(*it);

        // Se não achou, retira o último do path
        } else {
            path.pop_back();
        }

        // Deixa o ponto atual como o próximo da lista
        currentPoint = path.back();
    }

    return path;
}

// Recursiva ou Implicita
list<int> aux(list<int> maze[], int start, int finish) {
    unordered_set<int> visited;
    list<int> path;
    solve(maze, start, finish, visited, path);
    return path;
}

bool solve(list<int> maze[], int start, int finish, unordered_set<int>& visited, list<int>& path) {
    if (start == finish) {
        path.push_back(start);
        return true;
    } 

    visited.insert(start);
    list<int>::iterator it = maze[start].begin();
    while (it != maze[start].end()) {
        if (!visited.count(*it)) {
            if (solve(maze, *it, finish, visited, path)) {
                path.push_front(start);
                return true;
            }
        }
        it++;
    }
    return false;
}