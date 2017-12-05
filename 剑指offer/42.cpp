/*对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。*/
class Solution {
public:
	void fun(string &s,int start,int end)
    {
        char temp;
        while(start<end)
        {
            temp=s[start];
            s[start]=s[end];
            s[end]=temp;
            start++;
            end--;
        }
    }
    string LeftRotateString(string str, int n) {
        int len=str.length();
        if(0==len || 0==n)
            return str;
        string &temp=str;
        fun(temp,0,n-1);
        fun(temp,n,len-1);
        fun(temp,0,len-1);
        return str;
    }
};