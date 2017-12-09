/*请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
例如 a b c e
	 s f c s 
	 a d e e 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。*/
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
    	vector<bool> used(strlen(matrix), false);
        bool* flags = new bool[rows*cols];
        for(int i=0;i<rows;i++){
        	for(int j=0;j<cols;j++){
                if(isPath(matrix, rows,cols,i, j,str,0,used))
                    return true;
            }
        }
        return false;
    }
private:
    bool isPath(char* matrix,int rs,int cs ,int row, int col, char* str,int len,vector<bool> used)
    {
        if(len == strlen(str))
            return true;
        int idx  = col+row*cs;
        if(row<0 || row>=rs || col<0 || col>=cs || used[idx] == true || matrix[idx] != str[len])
            return false;
        used[idx] = 1;
        int res =  isPath( matrix,rs,cs ,row-1, col,str,len+1,used) ||  
                    isPath( matrix,rs,cs ,row, col-1,str,len+1,used) ||  
                    isPath( matrix,rs,cs ,row+1, col,str,len+1,used) ||  
                    isPath( matrix,rs,cs ,row, col+1,str,len+1,used);  
        if(res==true)
            return true;
        used[idx] = 0;
        return false;
    }
};