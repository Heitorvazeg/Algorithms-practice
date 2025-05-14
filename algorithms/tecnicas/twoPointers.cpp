/*Two Pointers:
Usa dois ponteiros ou referencias para continuar o "track" de arrays ou strings.
Pode processar 2 elementos por loop ao invez de apenas 1.
Um anda devagar e o outro com o dobro de sua velocidade.*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    std::vector<int> vetor = {2, 7, 11, 15};
}

vector<int> twoSum(vector<int>& nums, int target) {
    int i = 0;
    int j = nums.size()-1;

    while (i <= j) {
        int soma =  nums[i] + nums[j];

        if (soma == target) {
            std::vector<int> a = {i, j};
            return a;
        }
        if (soma < target) {
            i++;

        } else {
            j--;
        }
    }
    std::vector<int> a = {-1, -1};
    return a;
}

bool ehPalindromo(string s) {
    int i =  0;
    int j =  s.size()-1;

    while (i <= j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

vector<int> removeDuplicatas(vector<int>& v) {
    if (v.empty()) return v;

    int i = 0;

    for (int j = 0; j < v.size(); j++) {
        if (v[j] != v[i]) {
            i++;
            v[i] = v[j];
        }
    }
    return v;
}

