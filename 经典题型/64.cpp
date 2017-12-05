/*栈的逆序*/
class StackReverse {
public:
    vector<int> reverseStack(vector<int> A, int n) {
        stack<int>temp;
        for(int i=n-1;i>=0;i--)
        {
            temp.push(A[i]);
        }
        reverse(temp);
        vector<int>res;
        while(!temp.empty())
        {
            res.push_back(temp.top());
            temp.pop();
        }
        return res;
    }
    void reverse(stack<int> &A)
    {
        int i;
        if(A.empty()) return;
        i = getLast(A);
        reverse(A);
        A.push(i);
    }
    int getLast(stack<int> &A)
    {
        int val = A.top();
        A.pop();
        if(A.empty())
        {
            return val;
        }
        else
        {
            int last = getLast(A);
            A.push(val);
            return last;
        }
    }
};