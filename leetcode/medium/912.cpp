/*Implementação merge sort*/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        nums = mergeSort(nums);
        return nums;
    }

    vector<int> mergeSort(vector<int> vetor) {
        int len = vetor.size();

        if (len <= 1) return vetor;

        int mid = len / 2;
        vector<int> left(vetor.begin(), vetor.begin() + mid);
        vector<int> right(vetor.begin() + mid, vetor.end());

        left = mergeSort(left);
        right  = mergeSort(right);
        merge(left, right, vetor);
        return vetor;
    }

    void merge(vector<int>& esquerda, vector<int>& direita, vector<int>& vetor) {
        int leftSize = vetor.size() / 2;
        int rightSize = vetor.size() - leftSize;

        int i = 0, l =  0, r = 0;

        while (l < leftSize && r <  rightSize) {
            if (esquerda[l] < direita[r]) {
                vetor[i] = esquerda[l];
                i++;
                l++;

            } else {
                vetor[i] = direita[r];
                r++;
                i++;
            }
        }
        while (l < leftSize) {
            vetor[i] = esquerda[l];
            l++;
            i++;
        }
        while (r < rightSize) {
            vetor[i] = direita[r];
            r++;
            i++;
        }
    }
};