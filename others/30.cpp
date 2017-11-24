/*动态规划_最大子段和问题
N个整数组成的序列a[1],a[2],a[3],…,a[n]，求该序列如a[i]+a[i+1]+…+a[j]的连续子段和的最大值。
当所给的整数均为负数时和为0。 例如：-2,11,-4,13,-5,-2，和最大的子段为：11,-4,13。和为20*/
#include<iostream>
#include <vector>
using namespace std;
/*
定义endmax表示以当前元素结尾的最大子段和
endmax = answer = a[1]
for i = 2 to n do
    endmax = max(endmax, 0) + a[i]
    answer = max(answer, endmax)
endfor
*/
class MaxSum {
public:
    int getMaxSum(vector<int> A, int n) {
    	int start = 0;
		int answerstart = 0, answerend = 0;
		int endmax = A[0], answer = A[0];
		for(int end=1;end<n;end++)
		{
			if(endmax > 0){
			   endmax += A[end];
			} 
			else
			{
			    endmax = A[end];
				start = end;
			}
			if (endmax > answer)
			{
			    answer = endmax;
				answerstart = start;
				answerend = end;
			}
		}
		return answer;
    }
};
void main()
{
	MaxSum ms;
	int n,res;
	vector<int> A;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    res = ms.getMaxSum(A,n);
    printf("%d", res);
}