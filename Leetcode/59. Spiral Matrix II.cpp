/*Spiral Matrix II:Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > matrix(n,vector<int>(n,0));
        if(n <= 0){
            return matrix;
        }
        int count = n * n;
        int index = 1;
        int x = 0,y = -1;
        while(index <= count){
            // right
            ++y;
            while(y < n && matrix[x][y] == 0){
                matrix[x][y++] = index;
                ++index;
            }
            --y;
            // down
            ++x;
            while(x < n && matrix[x][y] == 0){
                matrix[x++][y] = index;
                ++index;
            }
            --x;
            // left
            --y;
            while(y >= 0 && matrix[x][y] == 0){
                matrix[x][y--] = index;
                ++index;
            }
            ++y;
            // up
            --x;
            while(x >= 0 && matrix[x][y] == 0){
                matrix[x--][y] = index;
                ++index;
            }
            ++x;
        }
        return matrix;
    }
};