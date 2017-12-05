/*对于两个32位整数a和b，请设计一个算法返回a和b中较大的。但是不能用任何比较判断。若两数相同，返回任意一个。 给定两个整数a和b，请返回较大的数*/
#include<iostream>
using namespace std;
class Compare {
public:
    int getMax(int a, int b) {
        // 我们可以得到a-b的符号，根据该符号决定返回a或b
        int c=a-b;
        int flag=((c>>31)&1^1);
        int flag_inv=1-flag;
        return flag*a+flag_inv*b;
    }
};