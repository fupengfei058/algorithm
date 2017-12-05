/*二叉树_二叉搜索树与双向链表
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。 
思路：
1.核心是中序遍历的非递归算法。
2.修改当前遍历节点与前一遍历节点的指针指向*/
#include <iostream>
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
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
    	if(pRootOfTree == NULL) return NULL;
        stack<TreeNode* > stack;
        TreeNode* root = NULL;
        TreeNode* pre = NULL;
        while(pRootOfTree || !stack.empty())
        {
			while(pRootOfTree)
			{
			    stack.push(pRootOfTree);
			    pRootOfTree = pRootOfTree->left;
			}
			if(!stack.empty())
			{
			    pRootOfTree = stack.top();
			    stack.pop();
			    if(root == NULL)
			    {
			        root = pRootOfTree;
			        pre = root;
			    }
			    else
			    {
			        pre->right = pRootOfTree;
			        pRootOfTree->left = pre;
			        pre = pRootOfTree;
			    }
			    pRootOfTree = pRootOfTree->right;
			}
        }
        return root;
    }
};