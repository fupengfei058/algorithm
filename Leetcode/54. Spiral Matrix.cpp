/*Spiral Matrix:Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return vector<int>();
        vector<int> ret;
        //输入矩阵行数
        int m = matrix.size() - 1;
        //输入矩阵的列数
        int n = matrix[0].size() - 1;
        for (int x = 0, y = 0; x <= m && y <= n; x++, y++)
        {
            //输出矩阵首行
            for(int j=y ; j<=n ; ++j)
            {
                ret.push_back(matrix[x][j]);
            }
            //输出矩阵最右列
            for (int i = x + 1; i <= m; ++i)
            {
                ret.push_back(matrix[i][n]);
            }
            //输出矩阵最底行
            for (int j = n - 1; j >= y && x != m; --j)
            {
                ret.push_back(matrix[m][j]);
            }
            //输出矩阵最左列
            for (int i = m - 1; i > x && y != n; --i)
            {
                ret.push_back(matrix[i][y]);
            }
            m--;
            n--;
        }

        return ret;
    }
};