/*输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。*/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL){
        	return NULL;
        }
        if(pRootOfTree->left == NULL && pRootOfTree->right == NULL){
        	leftLast = pRootOfTree;
        	return pRootOfTree;
        }
        TreeNode* pleft = Convert(pRootOfTree->left);
        if(pleft != NULL){
        	leftLast->right = pRootOfTree;
        	pRootOfTree->pleft = leftLast;
        }
        leftLast = pRootOfTree;
        TreeNode* pright = Convert(pRootOfTree->right);
        if(pright != NULL){
        	pright->left = pRootOfTree;
        	pRootOfTree->right = pright;
        }
        return pleft != NULL ? pleft : pRootOfTree;
    }
protected:
	TreeNode* leftLast = NULL;
};