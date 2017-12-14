/*Regular Expression Matching:Implement regular expression matching with support for '.' and '*'.*/
class Solution {
public:
    bool isMatch(string s, string p) {
        stack<char> sc;
        stack<int> si;
        stack<int> sj;
        int ls = s.size();
        int lp = p.size();
        int i, j, k;
        i = 0;
        j = 0;
        while (i < ls || j < lp) {
            if (j + 1 < lp && p[j + 1] == '*') {
                sc.push(p[j]);
                si.push(i);
                j += 2;
                sj.push(j);
            } else if (j < lp && (p[j] == '.' || s[i] == p[j])) {
                ++i;
                ++j;
            } else if (!sc.empty()) {
                k = si.top();
                if (k < ls && (sc.top() == '.' || sc.top() == s[k])) {
                    ++k;
                    i = si.top() = k;
                    j = sj.top();
                } else {
                    sc.pop();
                    si.pop();
                    sj.pop();
                }
            } else {
                break;
            }
        }
        bool res = (i == ls && j == lp);
        
        while (!sc.empty()) {
            sc.pop();
            si.pop();
            sj.pop();
        }
        
        return res;
    }
};