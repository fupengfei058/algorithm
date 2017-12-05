/*二叉树_完全二叉树判断
**思路: **如果当前节点没有左孩子但是有右孩子，则return false; 如果当前节点并不是左右孩子都有，则孩子必须为子叶节点，否则return false*/
#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
class CheckCompletion {
public:
    bool chk(TreeNode* root) {
        /*
        如果当前节点没有左孩子但是有右孩子，则return false
        如果当前节点并不是左右孩子都有，则孩子必须为子叶节点，否则return false
        */
        queue<TreeNode*> qe;
        int isEnd = 0;
        if(root==NULL) return true;
        qe.push(root);
        while(!qe.empty())
        {
            TreeNode* cur = qe.front();
            qe.pop();
            if(isEnd&(cur->left!=NULL || cur->right!=NULL))
            {
                return false;  
            }
            else if(cur->left==NULL && cur->right!=NULL)
            {
                return false;
            }
            else if(cur->left==NULL && cur->right==NULL)
            {
                isEnd = 1;
            }
            else if(cur->left!=NULL && cur->right==NULL)
            {
                isEnd = 1;
                qe.push(cur->left);   
            }
            else
            {
                qe.push(cur->left);
                qe.push(cur->right);
            }   
        }
        return true;
    }
};