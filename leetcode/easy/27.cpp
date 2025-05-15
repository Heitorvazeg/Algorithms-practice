/*Uso de Two Pointers*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;

        int k = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
                k = i;
            }
        }
        return k;
    }
};