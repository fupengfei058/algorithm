/*二叉树_遍历打印*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
//用递归方式实现二叉树的先序、中序和后序的遍历打印
class TreeToSequence {
public:
	void pre(TreeNode* rt, vector<int> &ret)
	{
		ret.push_back(rt.val);
		if(rt->left) pre(rt->left, ret);
		if(rt->right) pre(rt->right, ret);
	}
	void mid(TreeNode* rt, vector<int> &ret)
	{
		if(rt->left) mid(rt->left, ret);
		ret.push_back(rt.val);
		if(rt.right) mid(rt->right, ret);
	}
	void aft(TreeNode* rt, vector<int> &ret)
    {
        if(rt->left) aft(rt->left, ret);
        if(rt->right) aft(rt->right, ret);
        ret.push_back(rt->val);
    }
    vector<vector<int> > convert(TreeNode* root) {
        vector<int>A,B,C;
        vector<vector<int> >ret;
        pre(root,A);mid(root,B);aft(root,C);
        ret.push_back(A);ret.push_back(B);ret.push_back(C);
        return ret;
    }
};
class TreeToSequence2 {
public:
	void pre(TreeNode* rt, vector<int> &ret)
	{
		stack<TreeNode*> s;
		s.push(rt);
		TreeNode* cur;
		while(!s.empty())
        {
            cur = s.top();
            s.pop();
			ret.push_back(cur->val);
            if(cur->right)
            {
                s.push(cur->right);
            }
            if(cur->left)
            {
                s.push(cur->left);
            }
        }
	}
	void mid(TreeNode* rt, vector<int> &ret)
	{
		stack<TreeNode*> s;
		TreeNode* cur = rt;
		while(cur || !s.empty())
		{
			while(cur != NULL)
			{
				s.push(cur);
				cur = cur->left;
			}
			if(!s.empty())
            {
                //访问左孩子为空的节点
                cur = s.top();
                s.pop();
				ret.push_back(cur->val);
                cur = cur->right;//转向右孩子
            }
		}
	}
	void aft(TreeNode* rt, vector<int> &ret)
    {
        stack<TreeNode*> s1,s2;
        s1.push(rt);
        while(!s1.empty())
        {
            TreeNode* p = s1.top();
            s1.pop();
            s2.push(p);
            if(p->left != NULL)
            {
                s1.push(p->left);
            }
            if(p->right != NULL)
            {
                s1.push(p->right);
            }
        }
        while(!s2.empty())
        {
			ret.push_back(s2.top()->val);
            s2.pop();
        }
    }
};