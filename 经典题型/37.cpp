/*字符串_移位
对于一个字符串，请设计一个算法，将字符串的长度为len的前缀平移到字符串的最后。*/
#include<iostream>
#include<string>
using namespace std;
class Translation {
public:
    string stringTranslation(string A, int n, int len) {
    	len %= n;
    	severseString(A, 0, len - 1);
    	severseString(A, len, n - 1);
    	severseString(A, 0, n - 1);
    	return A;
    }
    void severseString(string& A, int left, int right)
    {
        while(left <= right)
        {
            swap(A[left++], A[right--]);
        }
     }
};