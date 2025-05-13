/*sliding window para solução*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int hLen = haystack.length();
        int nLen = needle.length();

        if (nLen > hLen) return -1;

        for (int i = 0; i < hLen; i++) {
            if  (haystack.substr(i, nLen) == needle) {
                return i;
            }
        }
        return -1;
    }
};
