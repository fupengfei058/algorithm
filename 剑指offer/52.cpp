/*请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。*/
class Solution {
public:
    bool isNumeric(char* string)
    {
    	if(string==NULL)
            return false;
        if(*string=='+'||*string=='-')
            ++string;
        if(*string=='\0')
            return false;
        while(*string!='\0'&&*string<='9'&&*string>='0') //到达第一个不是数字的位置
             ++string;
        bool flag=true;
        if(*string!='\0')
          {
             if(*string=='.') //若是小数  
               {
                  ++string;
                  while(*string!='\0'&&*string<='9'&&*string>='0') //到达第一个不是数字的位置
                     ++string;
                  if(*string=='e'||*string=='E') //小数的指数，如3.2e-12
                      flag=isExponent(&string);
               }
             else if(*string=='e'||*string=='E') //指数
               {
                  flag=isExponent(&string);
               }
             else
               flag=false;
          }
        return flag&&*string=='\0';
    }
    bool isExponent(char** string)
    {
        if(**string!='E'&&**string!='e')
           return false;
        ++(*string);                       //当前字符为'e'或'E',向后移动一位
        if(**string=='+'||**string=='-')   //当前字符为'+'或'-',向后移动一位
           ++(*string);
        if(**string=='\0')    //当前字符为'\0',说明e或E后面没有数字，则结束
            return false;
        while(**string!='\0'&&**string<='9'&&**string>='0')   //到达第一个不是数字的位置  
            ++(*string);
        if(**string=='\0')
            return true;
        else
            return false;
    }
};