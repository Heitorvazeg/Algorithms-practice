class Solution {
    // Naive Solution:
// For each substring of the string starting at index i, see 
// if it is a palindrome, and if so, se if it is the longest.

// Will go trough the string of size n, in a total of n/2*n times.
// Or N^2/2. But, it has also to calculute if is a palidrome. That turns
// to be N/2. So, N/2*N^2/2 = n^3/4.

// Optimized:
// O(n^2)
// Expand around a center.
// For each starting center position, we will expand to left and
// rigth indexes to see if it is equals, and store the maximum value
// of a palindrome.

// This algorithms checks if, given a certain center, the substring
// is a palindrome and its length.

// Do this to all possible centers with one and two centers.

public:
    tuple<int, int, int> expandAround(string s, int left, int right) {
        // Expands while its a possible index and proper palindrome.
        while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
            left -= 1;
            right += 1;
        }

        return {right - left - 1, left+1, right-1};
    }

    string longestPalindrome(string s) {
        int maxSize = 1;
        int leftAns = 0;
        int rightAns = 0;
        // Expand around for every starting center
        for (int i = 0; i < (int)s.size(); i++) {
            auto [sizeOdd, leftOdd, rightOdd] = expandAround(s, i, i);
            auto [sizeEven, leftEven, rightEven] = expandAround(s, i, i+1);

            // Sees if one of the values calculated is greater than max.
            if (sizeOdd > maxSize) {
                maxSize = sizeOdd;
                leftAns = leftOdd;
                rightAns = rightOdd;
            }
            if (sizeEven > maxSize) {
                maxSize = sizeEven;
                leftAns = leftEven;
                rightAns = rightEven;
            }
        }

        string ans;
        for (int i = leftAns; i <= rightAns; i++) {
            ans.push_back(s[i]);
        }

        return ans;
    }
};