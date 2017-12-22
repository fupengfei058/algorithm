/*Substring with Concatenation of All Words:You are given a string, s, and a list of words, words, that are all of the same length. 
Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty())
            return vector<int>();

        vector<int> ret;
        //记录所给words中每个单词的出现次数
        map<string, int> word_count;
        //每个单词的长度相同
        int word_size = strlen(words[0].c_str());
        int word_nums = words.size();
        //所给匹配字符串的长度
        int s_len = strlen(s.c_str());

        for (int i = 0; i < word_nums; i++)
            ++word_count[words[i]];

        int i, j;
        map<string, int> temp_count;
        for (i = 0; i < s_len - word_nums*word_size + 1; ++i)
        {
            temp_count.clear();
            for (j = 0; j < word_nums; j++)
            {
                //检验当前单词是否属于words以及出现的次数是否一致
                string word = s.substr(i + j*word_size, word_size);
                if (word_count.find(word) != word_count.end())
                {
                    ++temp_count[word];
                    //如果出现的次数与words不一致，则返回错误
                    if (temp_count[word] > word_count[word])
                        break;
                }
                else{
                    break;
                }              
            }
            //所有words内的单词,在i起始位置都出现，则将下标i存入结果的vector中
            if (j == word_nums)
            {
                ret.push_back(i);
            }
        }
        return ret;
    }
};