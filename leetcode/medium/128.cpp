class Solution {
    public:
    // Concept: Put all the elements in a unordered_set. Then, iterate through the array and see if the element-1 exists in the unordered_set. If so, just continue; if not, just start to sum +1 to every element in the sequence that exists.
    // O(2*N) or O(N)
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> setOfElements;
        setOfElements.reserve(nums.size());
        setOfElements.max_load_factor(0.7);

        for (int i = 0; i < (int)nums.size(); i++) {
            // Sets the set for querys
            setOfElements.insert(nums[i]);
        }

        int maxConsecutiveSequence = 1;
        for (auto i : setOfElements) {
            if (setOfElements.count(i-1)) continue;
            
            // Starts a new sequence with nums[i] as the initial value
            int sizeSequence = 1;
            int copyNumsi = i+1;
            while (setOfElements.count(copyNumsi)) {
                sizeSequence++;
                copyNumsi++;
            }

            // The max sequence is the answer
            maxConsecutiveSequence = max(maxConsecutiveSequence, sizeSequence);
        }

        return maxConsecutiveSequence;
    }
};