/*输入一棵二叉树，判断该二叉树是否是平衡二叉树。*/
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
		bool res = true;
		if(pRoot == NULL) return res;
		int d;
		res = isBalanced(pRoot, d);
		return res;
    }
    bool isBalanced(TreeNode* pRoot, int &d) {
		int dL,dR;
		bool res = true;
		dL = dR = 0;
		if(pRoot){
			res = isBalanced(pRoot->left,dL) && isBalanced(pRoot->right,dR);
			res = res && ( abs(dL - dR) <= 1 );
			d = max(dL,dR) + 1;
		}
		return res;
    }
};