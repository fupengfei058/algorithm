/*有一副由NxN矩阵表示的图像，这里每个像素用一个int表示，请编写一个算法，在不占用额外内存空间的情况下(即不使用缓存矩阵)，将图像顺时针旋转90度。*/
/*思路：第一步：先将矩阵以次对角线互换 （如果是逆时针则为主对角线）
       第二步：交换第i行到第n-i-1行
*/
class TransForm
{
public:
	vector<vector<int> > transformImage(vector<vector<int>mat >, int n){
		int temp;
		for (int i = 0; i < n; i++)
		{
			for(int j = 0; j < n-1-1; j++){
				temp = mat[i][j];
				mat[i][j] = mat[n-j-1][n-i-1];
				mat[n-j-1][mat[n-i-1]] = temp;
			}
		}
		for (int i = 0; i < n/2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				temp = mat[i][j];
				mat[i][j] = mat[n-i-1][j];
				mat[n-i-1][j] = temp;
			}
		}
		return mat;
	}
};
