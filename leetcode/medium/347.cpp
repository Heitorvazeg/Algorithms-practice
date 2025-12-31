class Solution {
    // Concept: Sort the array and place the elements in a map with values of how
    // many times did we see the element in the array. After, we only have
    // iterate through the map and find out the k greatests elements.

    // Optimized one: Use a heap.
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        priority_queue<pair<int, int>> pq;
        for (auto &p : freq) {
            pq.push({p.second, p.first});
        }

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};