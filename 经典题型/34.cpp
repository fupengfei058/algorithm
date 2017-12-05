/*动态规划_最长递增子序列
对于一个数字序列，请设计一个复杂度为O(nlogn)的算法，返回该序列的最长上升子序列的长度，
这里的子序列定义为这样一个序列U1，U2...，其中Ui < Ui+1，且A[Ui] < A[Ui+1]。*/
#include <vector>
#include <iostream>
using namespace std;
/*
以ai结尾的最长递增子序列记做Li,其长度记为b[i]
b[i] ={max(b[j])+1,0<=j<i且aj<ai}
*/
class AscentSequence {
public:
    int findLongest(vector<int> A, int n) {
    	vector<int> dp(n);
		dp[0] = 1;
		int maxLen = dp[0];
		for (int i = 1; i < n; ++i) {
			maxLen = 1;
			for (int j = 0; j < i; ++j) {
				if (A[j] < A[i]) {
					maxLen = max(maxLen, dp[j] + 1);
				}
			}
			dp[i] = maxLen;
		}
		for (int i = 0; i < n; ++i) {
			maxLen = max(maxLen, dp[i]);
		}
		return maxLen;
    }
};