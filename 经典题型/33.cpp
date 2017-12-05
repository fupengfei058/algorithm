/*动态规划_最长公共子序列
我们有两个字符串m和n，如果它们的子串a和b内容相同，则称a和b是m和n的公共子序列。子串中的字符不一定在原字符串中连续。 
例如字符串“abcfbc”和“abfcab”，其中“abc”同时出现在两个字符串中，因此“abc”是它们的公共子序列。此外，“ab”、“af”等都是它们的字串。*/
#include <iostream>
#include <vector>
using namespace std;
int max(int a, int b)
{
    return (a>b)? a:b;
}  
/**
 * 返回X[0...m-1]和Y[0...n-1]的LCS的长度
 */
int lcs(string &X, string &Y, int m, int n)
{
    // 动态规划表，大小(m+1)*(n+1)
    vector<vector<int>> table(m+1,vector<int>(n+1));
    for(int i=0; i<m+1; ++i)
    {
        for(int j=0; j<n+1; ++j)
        {
            // 第一行和第一列置0
            if (i == 0 || j == 0)
                table[i][j] = 0;

            else if(X[i-1] == Y[j-1])
                table[i][j] = table[i-1][j-1] + 1;

            else
                table[i][j] = max(table[i-1][j], table[i][j-1]);
        }
    }
    return table[m][n];
}
int main()
{
    string X = "ABCBDAB";
    string Y = "BDCABA";
    cout << "The length of LCS is " << lcs(X, Y, X.length(), Y.length());
    cout << endl;
    getchar();
    return 0;
}
// 求最长公共子字符串和最长子序列的区别在于：
//最长子字符串当str1[i] ！= str2[j]时，veca[i][j]长度要为0，而不是max{veca[i - 1][j], veca[i][j - 1]}