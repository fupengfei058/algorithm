/*请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。*/
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
    bool isSymmetrical(TreeNode* pRoot)
    {
    	if(pRoot==NULL) return true;
        bool res=isTreeSymmertic(pRoot->left,pRoot->right);
        return res;
    }
	bool isTreeSymmertic(TreeNode *pHead1,TreeNode *pHead2)
	{
		if (pRoot1 == NULL && pRoot2 == NULL){
            return true;
        }
        if (pRoot1 == NULL || pRoot2 == NULL){
            return false;
        }
        if (pRoot1->val != pRoot2->val){
            return false;
        }
        return isSymmetrical(pRoot1->left, pRoot2->right) && isSymmetrical(pRoot1->right, pRoot2->left);
	}
};