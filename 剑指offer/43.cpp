/*翻转单词顺序，例如：输入“I am a student.”，输出“student. a am I”。*/
class Solution {
public:
    string ReverseSentence(string str) {
		ReverseWord(str, 0, str.size() - 1); //先整体翻转
        int s = 0, e = 0;
        int i = 0;
        while(i < str.size())
        {
            while(i < str.size() && str[i] == ' ') //空格跳过
                i++;
            e = s = i; //记录单词的第一个字符的位置
            while(i < str.size() && str[i] != ' ') //不是空格 找单词最后一个字符的位置
            {
                i++;
                e++;
            }
            ReverseWord(str, s, e - 1); //局部翻转
        }
        return str;
    }
	void ReverseWord(string &str, int s, int e)
    {
        while(s < e)
            swap(str[s++], str[e--]);
    }
};