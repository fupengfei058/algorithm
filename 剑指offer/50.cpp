/*给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。*/
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
    	int len = A.size();
        vector<int> res;
        if(len == 0)
            return res;
        res.push_back(1);
        //B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]
        //先把A[0]*A[1]*...A[i]算出来
        for(int i = 0; i < len - 1; i++){
            res.push_back(res[i] * A[i]);
        }
        int temp = 1;
        //再乘以A[i-1]*A[i+1]*...*A[n-1]
        for(int i = len - 1; i >= 0; i--){
            res[i] *= temp;
            temp *= A[i];
        }
        return res;
    }
};