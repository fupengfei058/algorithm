/*字符串_正则表达式匹配
请实现一个函数用来匹配包括'.'和''的正则表达式。模式中的字符'.'表示任意一个字符，而''表示它前面的字符可以出现任意次（包含0次）。
在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"abaca"匹配，但是与"aa.a"和"ab*a"均不匹配
思路：
1.有效性检查
str不能有.* 
pattern模式中*前面必须有一个字符

2.匹配情况
定义s[i]和p[i]表示从i位置到结尾的字符串
1)  s[i],p[i]不相等时，而且P[i+1]！=*或者.,则return false
            			 如果P[i+1]=*则s[i]与p[i+2]继续比较
2) s[i],p[i]相等时,如果p[i+1]=*,比如s=xxxxzzzz,p=x*yyyy
                        如果p[i+1]不等于*时，则i++
*/
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        
      if(str==NULL||pattern==NULL)
      {
          return false;
      }
      for(int i=0;i<(int)strlen(str);i++)
      {
          if(str[i]=='.'||str[i]=='*')
          {
              return false;
          }
      }
        for(int i=0;i<(int)strlen(pattern);i++)
        {
            if(pattern[i]=='*'&&(i==0||pattern[i-1]=='*'))
            {
                return false;
            }
        }
      return expMatch(str,0,pattern,0);
    }
    
    bool expMatch(char* s,int si,char* p,int pi)
    {
       if(pi==(int)strlen(p))
       {
           return si==(int)strlen(s);
       }
        //注意p只有两个字符而且没有*时,要求满足p[i]==s[i]而且si不能为最后一个字符
       if(pi+1==(int)strlen(p)||p[pi+1]!='*')
       {
          return si!=(int)strlen(s)&&(s[si]==p[pi]||p[pi]=='.')
              &&expMatch(s,si+1,p,pi+1);
       }
       /*
       p[i+1]=*,s[i],p[i]相等时,比如s=xxxxzzzz,p=x*yyyy
       */
        while(si!=(int)strlen(s)&&(s[si]==p[pi]||p[pi]=='.'))
        {
            if(expMatch(s,si,p,pi+2))
            {
                return true;
            }
            si++;
        }
       return expMatch(s,si,p,pi+2);
    }
};