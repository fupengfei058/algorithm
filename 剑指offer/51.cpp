/*请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配*/
/*分析：递归实现
每次分别在str 和pattern中取一个字符进行匹配，如果匹配，则匹配下一个字符，否则，返回不匹配。
设匹配递归函数 match(str, pattern)。
如果模式匹配字符的下一个字符是‘*’:
•如果pttern当前字符和str的当前字符匹配，：有以下可能情况
（1）pttern当前字符能匹配 str 中的 0 个字符：match(str, pattern+2)
（2）pttern当前字符能匹配 str 中的 当前 字符：match(str+1, pattern)
•如果pttern当前字符和和str的当前字符不匹配
pttern当前字符能匹配 str 中的 0 个字符：(str, pattern+2)
如果模式匹配字符的下一个字符不是‘*’，进行逐字符匹配。
对于 ‘.’ 的情况比较简单，’.’ 和一个字符匹配 match(str+1, pattern+1)
另外需要注意的是：空字符串”” 和 “.*” 是匹配的*/
class Solution {
public:
    bool match(char* str, char* pattern)
    {
    	if(*str=='\0')
        {
            if(*pattern=='\0'||(*(pattern+1)=='*'&&*(pattern+2)=='\0')) //空串和“b*”是匹配的
                return true;
            else return false;
        }
        if(*pattern=='\0')
            return false;
        if(*(pattern+1)=='*'){
            if(*pattern==*str||*pattern=='.')
                return match(str+1,pattern)||match(str,pattern+2); 
            //两种情况，一种是出现次数大于0，那就是str+1，pattern不变;另一种是出现次数等于0
            else return match(str,pattern+2);//不符合要求，当做出现次数为0
        }
        if(*pattern==*str||*pattern=='.')
            return match(str+1,pattern+1);
        return false;
    }
};