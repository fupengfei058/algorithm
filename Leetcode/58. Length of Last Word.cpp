/*Length of Last Word:Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        char c;
        int end = s.size() - 1;
        while (end >= 0 && s[end] == ' ')
            end--;

        int start = end - 1;
        while (start >= 0 && s[start] != ' ')
            start--;

        if (end == -1)
            return 0;

        return end - start;
    }
};