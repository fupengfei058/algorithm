/*输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。*/
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
    	if(sequence.empty())
            return false;
        bool rst;
        rst=_doverify(sequence,0,sequence.size()-1);
        return rst;
    }
    bool _doverify(vector<int> sequence,int start,int end){
        if(start>end)
            return true;

        int i;
        for(i=start;i<end;i++)
            if(sequence[i]>sequence[end])
                break;

        int pivot=i;
        for(;i<end;i++)
            if(sequence[i]<sequence[end])
                return false;

        return _doverify(sequence,start,pivot-1)&&_doverify(sequence,pivot,end-1);
    }
};