/*二叉树_平衡二叉树判断*/
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
/*
 * 判断树是否是平衡的有两个条件：
 * 1. 自身的左右子树深度差值<=1
 * 2. 自身的左右子树都为平衡树
 * 但如此计算深度时每次都有重复计算，复杂度太高
 * 因而改进：对每一层做检查时不急于先求出该层高度，而是逐层向下递归，因而返回值是逐层向上的，
 * 若底下有不平衡的直接跳出，最后才会轮到根节点层上看是否为平衡
*/
class Balance {
public:
    bool checkTree(TreeNode* root ,int &high)
    {
        if(root == NULL)
        {
            high = 0;
            return true;
        }
        int leftHigh,rightHigh;
        if(!checkTree(root->left,leftHigh) || !checkTree(root->right,rightHigh))
        {
            return false;
        }
        if(abs(leftHigh-rightHigh)>1)return false;
        high = (leftHigh>rightHigh?leftHigh:rightHigh)+1;
        return true;
    }
    bool isBalance(TreeNode* root) {
       int high = 0;
       return checkTree(root, high);
    }
};