/*Implementação de sliding window*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();

        unordered_map<char, int> map;
        int i = 0;
        int max = 0;

        map[s[i]] = i;
        for (int j = 1; j < s.size(); j++) {
            if (map.count(s[j]) && map[s[j]] >= i) {
                i = map[s[j]]+1;
            }
            map[s[j]] = j;

            if (j - i + 1 > max) {
                max = j - i + 1;
            }
        }
        return max;
    }
};

