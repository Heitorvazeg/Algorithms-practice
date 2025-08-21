/* Segment Tree é uma árvore binário que auxilia a responder consultas em
intervalos. Soma, minimo, maximo no intervalo...
Construção O(N); consulta O(log n); atualização O(Log n)

Pega um array e separa em uma árvore binário para cada intervalo, com o valor, desejado
seja min, max, soma...
A raiz representa todo o array.
Filho esquerdo é do indice 0 até o mid
Filho direito é do indice mid+1 até size-1*/

#include <bits/stdc++.h>

using namespace std;

struct segTree
{
    int n;
    vector<long long> tree;

    segTree(vector<int>&arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n-1);
    }

    void build(vector<int>& arr, int node, int l, int r) {
        // L -> Lado esquerdo. R -> Lado direito.
        // L inicia em 0, R em size-1.
        if (l == r) {
            tree[node] = arr[l];

        } else {
            int mid = (l + r) / 2;
            build(arr, 2 * node, l, mid);
            build(arr, (2 * node) + 1, mid + 1, r);
            // 2 * Node sempre dá o filho esquerdo.
            // 2 * Node + 1 sempre dá o filho direito.
            tree[node] = tree[2 * node] + tree[(2 * node) + 1];
        }
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0; // Fora do intervalo.
        if (ql <= 1 && r <= qr) return tree[node]; // Totalmente dentro.
        
        int mid = (l + r) / 2;
        return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
    }

    long long query(int l, int r) {return query(1, 0, n - 1, l, r);}
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    segTree st(arr);

    cout << st.query(1, 3);
}
