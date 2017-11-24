/*请编写一个方法，实现整数的乘法、减法和除法运算(这里的除指整除)。只允许使用加号。
给定两个正整数int a,int b,同时给定一个int type代表运算的类型，1为求a ＊ b，0为求a ／ b，-1为求a － b。请返回计算的结果，保证数据合法且结果一定在int范围内*/
/*
    1. a*b：将问题转换成|b|个a相加，或者|a|个b相加，最后根据a、b的符号确定返回值的符号。
    2.  a-b：转化成a+[-b]补，而[b]补与[-b]补之间的转换关系：连同符号位一起按位取反，再加1
*/
#include<iostream>
#include<string>
using namespace std;
class AddSubstitution {
public:
    int calc(int a, int b, int type) {
    	swich(type) {
    		case 1:
    			return multiply(a, b);
    		case 0:
    			return divide(a, b);
    		default:
    			return minus(a, b);
    	}
    }
	int multiply(int a, int b) {
		if(abs(a) < abs(b)){
			a^=b;
			b^=a;
			a^=b;
		}
		int sum = 0;
		for (int i = 0; i < abs(b); ++i)
		{
			sum+=a;
		}
		return b > 0 ? sum : ~sum+1;
	}
	int divide(int a, int b) {
		// b * x = a 求x
		int sum = 0;
		unsigned int count = 0;
		while(sum<abs(a)){
			sum+=abs(b);
			count++;
		}
		sum = sum>abs(a)?--count:count;
		//a b同号返回正数
		return  ((a>>31)^(b>>31))==0?count:~count+1;
	}
	int minus(int a, int b) {
		int rb = ~b+1;
		return a+rb;
	}
};