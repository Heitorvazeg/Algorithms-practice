/*Slinding Window algoritmo:
"Olhe pela janela e compare apenas o que você pode ver", o mundo é o valor, e a janela é seu 
padrao. Vai comparar o padrão aos valores do mundo.*/

#include <iostream>
#include <string>
#include <string>
#include <algorithm>
#include <vector>

/*strings*/
int main() {
}

int occurrences(std::string s, std::string p)  {
    int count = 0;
    int sLen = s.length();
    int pLen = p.length();

    if (pLen > sLen) return -1;

    for (int i = 0; i <= sLen; i++){
        if (s.substr(i, pLen) == p) {
            count++;
        }
    }
    return count;
}

int sumMaxOfPieceArray(std::vector<int> a, int k) {
    int n = a.size();
    if(n < k) return -1;
    int windowSum = 0;
    int maxSum = 0;

    for (int i = 0; i < k;  i++) {
        windowSum += a[i];
    }
    maxSum = windowSum;

    for (int end = k; end < n; end++) {
        windowSum += a[end] - a[end - k];
        maxSum = std::max(windowSum, maxSum);
    }
    return maxSum;
}