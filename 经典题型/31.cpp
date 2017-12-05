/*动态规划_矩阵取值问题
一个N*N矩阵中有不同的正整数，经过这个格子，就能获得相应价值的奖励，从左上走到右下，只能向下向右走，求能够获得的最大价值*/
#include<iostream>
#include <vector>
using namespace std;
 
int maxPath(vector<vector<int> > &num) {
	unsigned int m = num.size();
    vector<vector<int> > sum;
	sum[0][0] = num[0][0];
	for(int i=0;i<m;++i)
	{
		 for(int j=0;j<m;++j)
		{
			sum[i][j]=max(sum[i-1][j],sum[i][j-1])+num[i][j];
		}
	}
    return sum[m-1][m-1];
}