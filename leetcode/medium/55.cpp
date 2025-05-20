/* Implementação de greedy*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxD = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > maxD) return false;
            maxD = std::max(maxD, i + nums[i]);
        }

        return true;
    }
};