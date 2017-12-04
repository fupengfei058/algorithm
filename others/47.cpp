/*二叉树_层次遍历
给定二叉树的根结点root，请返回打印结果，结果按照每一层一个数组进行储存，所有数组的顺序按照层数从上往下，且每一层的数组内元素按照从左往右排列
思路:借助队列，何时换行?
定义两个指针last表示当前行的最右，nLast表示下一行的最右，当nLast==last时准备换行*/
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

class TreePrinter {
public:
    vector<vector<int> > printTree(TreeNode* root) {
         vector<vector<int>> allTreeValues;
        vector<int> treeValues;
        vector<TreeNode*> treeNodes;
        if (!root) return allTreeValues;
		//last表示当前行的最右，nLast表示下一行的最右
        TreeNode *last=root;
        TreeNode *nlast=root;
        treeNodes.push_back(root);
        while(!treeNodes.empty())
        {
            TreeNode *temp=treeNodes[0];
            treeValues.push_back(temp->val);
            if(temp->left)
            {
               nlast=temp->left;
               treeNodes.push_back(temp->left);
            }
             if(temp->right)
            {
               nlast=temp->right;
               treeNodes.push_back(temp->right);
            }
            if(temp==last)
            {
                last=nlast;
                allTreeValues.push_back(treeValues);
                treeValues.clear();
            }
            vector<TreeNode*>::iterator it=treeNodes.begin();
            treeNodes.erase(it);
        }
        return allTreeValues;
    }
};