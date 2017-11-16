/*大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。n<=39*/
class Solution {
public:
    int Fibonacci(int n) {
		int a=1,b=1,result=0;  
        if(n<0){  
            return 0;  
        }else if(n==1||n==2){  
            return 1;  
        }else {  
            for(int i=3;i<=n;i++){  
                result=a+b;  
                a=b;  
                b=result;  
            }  
        }  
        return result; 
    }
};