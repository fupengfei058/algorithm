/*请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。*/
class Solution {  
public:  
    void replaceSpace(char *str,int length) {  
        int spaceNum = 0;  
              
        for(int i=0; i<length; i++)  
        {  
            if(str[i] == ' ')  
                spaceNum++;             
        }
        int newIndex=length+2*spaceNum;  
        char *index=str+length;  
        while(index>=str)  
        {  
            if(*index==' ')  
            {  
                str[newIndex--]='0';  
                str[newIndex--]='2';  
                str[newIndex--]='%';  
            }  
            else{  
                str[newIndex--]=*index;  
            }  
            index--;  
        }
    }  
};  