class Solution {
    // Naive Solution:
    // Concept: We see all the strings and place them in groups of anagrams.
    // If is a new group (with new characteres), we add one more group.
    // To see if it is in one certain group, we sort de anagram and put it in
    // a hash map. If the sort of the word matchs the hash, them there is a group
    // with the same letters. If not, add one more hash in the map.
    // O(n log n * 100) -> O(100 * n log n)

    // Optimal one:
    // Maybe not sort would make the algorithm faster. But, we would have
    // to find another way of seeing if the word is another anagram.

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // If strs is empty, returns a empty matrix
        if (strs.empty()) {
            vector<vector<string>> v;
            return v;
        }
        // Answer matrix with all the anagrams grouped.
        vector<vector<string>> Anagrams;
        // Aux that we use to put the indexes in the matrix
        int IndexesGroupsAux = 0;
        // Map that find the index of the group anagram with another anagram.
        unordered_map<string, int> GroupsAnagrams;

        // Go through the vector and set wich anagram to your especific group.
        for (int i = 0; i < (int)strs.size(); i++) {
            // Sorted anagram to find its group.
            string s = strs[i];
            sort(s.begin(), s.end());

            // See if exist a group of anagrams
            if (GroupsAnagrams.count(s)) {
                // If exists, put in the group.
                Anagrams[GroupsAnagrams[s]].push_back(strs[i]);

            // If not, creates another group of anagrams
            } else {
                // Create another group
                GroupsAnagrams[s] = IndexesGroupsAux;
                // Update the new index aux
                IndexesGroupsAux++;

                // Vector aux to put into Anagrams
                vector<string> vectorAux;
                vectorAux.push_back(strs[i]);
                Anagrams.push_back(vectorAux);
            }
        }

        return Anagrams;
    }
};