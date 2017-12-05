/*动态规划_最小编辑代价
对于两个字符串A和B，我们需要进行插入、删除和修改操作将A串变为B串，定义c0，c1，c2分别为三种操作的代价。
请设计一个高效算法，求出将A串变为B串所需要的最少代价*/
/*  分析：
    dp[i][j]代表用 str1[0~i-1]编辑成str2[0~j-1]的最小代价
分析简单情况：
    dp[0][j]:即把一个空串编辑成str2[0~j-1]的代价则即将j个字符全部插入即
        dp[0][j] = j*c0;
    dp[i][0]:即把str1[0~i-1]编辑成空串的代价,即将i个字符全部删除即
        dp[i][0] = i*c1
    dp[i][j]:分四种情况：
    1) 先把str1[0~i-1]编辑成str1[0~i-2],在把str1[0~i-2]编辑成str2[0~j-1]
        dp[i][j] = dp[i-1][j] + c1;
    2) 先把str1[0~i-1]编辑成str2[0~j-2],在把str2[0~j-2]编辑成str2[0~j-1]
        dp[i][j] = dp[i][j-1] + c0;
    3) 如果str1[i-1] != str2[j-1],则可以先将str1[0~i-2]编辑成str2[0~j-2],然后进行替换
        dp[i][j] = dp[i-1][j-1] + c2;
    4) 如果str1[i-1] == str2[j-1],则直接将str1[0~i-2]编辑成str2[0~j-2]
        dp[i][j] = dp[i-1][j-1]
    从以上情况中选择代价最小的一种情况
*/
#include<iostream>
#include<vector>
using namespace std;
class MinCost {
public:
    int findMinCost(string A, int n, string B, int m, int c0, int c1, int c2) {
        if(n <= 0 || m <= 0)
            return 0;
        vector< vector<int> > dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i < n + 1; i++)
            dp[i][0] = c1 * i;
        for(int j = 1; j < m + 1; j++)
            dp[0][j] = c0 * j;
         
        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j < m + 1; j++)
            {
                if(A[i - 1] == B[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = dp[i - 1][j - 1] + c2;
                dp[i][j] = min(dp[i][j - 1] +  c0, dp[i][j]);
                dp[i][j] = min(dp[i - 1][j] +  c1, dp[i][j]);
            }
        }
        return dp[n][m];
    }
};