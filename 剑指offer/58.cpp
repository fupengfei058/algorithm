/*请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。*/
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > result;
        
        if(pRoot == NULL)
            return result;
        
        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;
        stk1.push(pRoot);
        TreeNode* tmp;
        vector<int> tLevel;
          
        while(!stk1.empty() || !stk2.empty())
        {
            if(!stk1.empty())
            {
                while(!stk1.empty())
                {
                    tmp=stk1.top();
                    tLevel.push_back(tmp->val);
                    if(tmp->left)
                        stk2.push(tmp->left);
                    if(tmp->right)
                        stk2.push(tmp->right);
                    stk1.pop();
                }
                result.push_back(tLevel);
                tLevel.clear();
            }
            else
            {
                while(!stk2.empty())
                {
                    tmp=stk2.top();
                    tLevel.push_back(tmp->val);
                    if(tmp->right)
                        stk1.push(tmp->right);
                    if(tmp->left)
                        stk1.push(tmp->left);
                    stk2.pop();
                }
                result.push_back(tLevel);
                tLevel.clear();
            }
        }
        return result;
    }
};