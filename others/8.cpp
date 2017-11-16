/*请编写一个算法，若MxN矩阵中某个元素为0，则将其所在的行与列清零。*/
/*思路:首先找到需要变为0的行和列号，记录在矩阵row和col中，若需要变为0则记为1，反之记为0，最后清零*/
class Clearer {
public:
    vector<vector<int> > clearZero(vector<vector<int> > mat, int n)
    {
    	vector<bool> row(n),col(n);
    	for (int i = 0; i < n; i++)
    	{
    		for (int j = 0; j < n; j++)
    		{
    			if(mat[i][j] == 0)
    			{
    				row[i] = true;
    				col[j] = true;
    			}
    		}
    	}
    	for (int i = 0; i < n; i++)
    	{
    		for (int j = 0; j < n; j++)
    		{
    			if (row[i] || col[j])
    			{
    				mat[i][j] = 0;
    			}
    		}
    	}
    	return mat;
    }
};