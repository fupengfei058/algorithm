/*在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置*/
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
    	if(str.empty())
            return -1;
        int* hashTable = new int[256];
        for(int i = 0;i<256;++i)
        {
            hashTable[i] = 0;
        }
        for(int i = 0;i<str.length();++i)
        {
            ++hashTable[str[i]];
        }
        for(int i = 0;i<str.length();++i)
        {
            if(hashTable[str[i]] == 1)
                return i;
        }
        return -1;
    }
};