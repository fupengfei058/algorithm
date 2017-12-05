/*数组_最大子方阵
有一个方阵，其中每个单元(像素)非黑即白(非0即1)，请设计一个高效算法，找到四条边颜色相同的最大子方阵。
给定一个01方阵mat，同时给定方阵的边长n，请返回最大子方阵的边长。保证方阵边长小于等于100。
测试样例：
[[1,1,1],[1,0,1],[1,1,1]],3
返回：3
思路：
任何一个点的下方(包括自己)1的个数存于数组bottom[i][j]
任何一个点的右边(包括自己)1的个数存于数组right[i][j]
数组分别往上和往左填充
检验四条边颜色是否相同为时,往右或往下跳k个判断1个数是否为k或为0个*/
class SubMatrix {
public:
    int maxSubMatrix(vector<vector<int> > mat, int n) {
      
        if(n == 0) return 0;
        vector<vector<int> > matA = mat;//坐标点下方连续1的个数
        vector<vector<int> > matB = mat;//坐标点右方连续1的个数
        vector<vector<int> > matAA = mat;//坐标点下方连续0的个数
        vector<vector<int> > matBB = mat;//坐标点右方连续0的个数
        //数组分别往上和往左填充
        //检验时,往右或往下跳边长个判断1或者0的个数是否为边长长度
        int i,j;
        int len = 0;
        int wide;
        for(i=n-1;i>=0;--i){
            for(j=n-1;j>=0;--j){
                if(mat[i][j] == 0){
                    matA[i][j] = 0;
                    matB[i][j] = 0;
                    if(i == n-1){
                        matAA[i][j] = 1;
                    }else{
                        matAA[i][j] = matAA[i+1][j]+1;
                    }
                    if(j == n-1){
                        matBB[i][j] = 1;
                    }else{
                        matBB[i][j] = matBB[i][j+1]+1;
                    }
                }else {
                    if(i == n-1){
                        matA[i][j] = 1;
                    }else{
                        matA[i][j] = matA[i+1][j]+1;
                    }
                    if(j == n-1){
                        matB[i][j] = 1;
                    }else{
                        matB[i][j] = matB[i][j+1]+1;
                    }
                    matAA[i][j] = 0;
                    matBB[i][j] = 0;
                }
            }
        }
       for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(mat[i][j] == 0){
                    wide = min(matAA[i][j],matBB[i][j]);
                    while(wide>0){
                        if(matAA[i][j+wide-1] >= wide && matBB[i+wide-1][j] >= wide){
                            len = len<wide?wide:len;
                        }
                        wide--;
                    }
                }else{
                    wide = min(matA[i][j],matB[i][j]);
                    while(wide>0){
                        if(matA[i][j+wide-1] >= wide && matB[i+wide-1][j] >= wide){
                            len = len<wide?wide:len;
                        }
                        wide--;
                    }
                }
            }
        }
        return len;
    }
};