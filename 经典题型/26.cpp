/*有一个整型数组A，其中只有一个数出现了奇数次，其他的数都出现了偶数次，请打印这个数。
要求时间复杂度为O(N)，额外空间复杂度为O(1)。给定整形数组A及它的大小n，请返回题目所求数字。*/
#include<iostream>
#include<vector>
using namespace std;
class OddAppearance {
public:
    int findOdd(vector<int> A, int n) {
        unsigned int ec = 0;
        for(int i=0;i<n;i++)
        {
            ec ^= A[i];
        }
        return ec;
    }
};