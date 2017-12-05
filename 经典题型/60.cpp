/*查找和排序_最短子数组
对于一个数组，请设计一个高效算法计算需要排序的最短子数组的长度。*/
#include <iostream>
#include <vector>
using namespace std;
class Subsequence {
public:
    int shortestSubsequence(vector<int> A, int n) {
        int max=A[0],min=A[n-1],i,rd1,rd2;
        for(i=1,rd1=0;i<n;i++)
        {
            if(A[i]>=max)
            {
              max=A[i];  
            }
           else
            {
              rd1=i;  
            }
        }
        for(i=n-2,rd2=n-1;i>=0;i--)
        {
            if(A[i]<=min)
            {
              min=A[i];  
            }  
            else
            {
              rd2=i;  
            }
                
        }
       if(!rd1) return 0;
       return rd1-rd2+1;
    }
};