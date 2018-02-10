/*Unique Paths:A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        //dp Fn=Fn-1+Fn
        vector<int> vec(n, 1);
        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                vec[j]+=vec[j-1];
            }
        }
        return vec[n-1];
    }
};