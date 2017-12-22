/*Implement strStr():Implement strStr().Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.*/
class Solution {
public:
    int strStr(string haystack, string needle) {
    	const string &s = haystack;
        const string &p = needle;
        int ls = s.size();
        int lp = p.size();
        int i, j;
        for (i = 0; i <= ls - lp; ++i) {
            for (j = 0; j < lp; ++j) {
                if (s[i + j] != p[j]) {
                    break;
                }
            }
            if (j == lp) {
                return i;
            }
        }
        return -1;
    }
};