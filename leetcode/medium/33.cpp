/*Busca binária em array rotacionado*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int e = 0, d = nums.size() - 1;

        while (e <= d) {
            int m = e + (d - e) / 2;

            if (nums[m] == target) return m;

            if (nums[e] <= nums[m]) {
                if (nums[e] <= target && target < nums[m]) {
                    d = m - 1;
                } else {
                    e = m + 1;
                }
            }
            else {
                if (nums[m] < target && target <= nums[d]) {
                    e = m + 1;
                } else {
                    d = m - 1;
                }
            }
        }
        return -1;
    }
};