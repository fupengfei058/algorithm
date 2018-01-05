/*Rotate Image:You are given an n x n 2D matrix representing an image.Rotate the image by 90 degrees (clockwise).*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return ;
        int mid = matrix.size()/2, n = matrix.size();
        for (int i = 0; i < mid; ++i) // 上下翻转
            for (int j = 0; j < n; ++j)
                swap(matrix[i][j], matrix[n-i-1][j]);
        for (int i = 0; i < n; ++i) // 转置
            for (int j = i+1; j < n; ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
};