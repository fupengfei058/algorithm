/*输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）*/
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    	int len = pushV.size();
        if (len == 0 || len != popV.size())
            return false;
        int i, j;
        stack<int> stk;
        i = 0;
        j = 0;
        stk.push(pushV[i ++]);
        while (j < len) {
            /* 当前栈顶元素==出栈序列中的元素 */
            if (popV[j] == stk.top()) {
                stk.pop();
                ++ j;
                continue;
            }
            if (i < len)
                stk.push(pushV[i ++]);
            else 
                break;
        } 
        if (stk.empty())
            return true;
        else
            return false;
    }
};