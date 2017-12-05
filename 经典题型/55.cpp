/*二叉树_树的子结构
输入两颗二叉树A，B，判断B是不是A的子结构。 
思路：第一步 在树A中找到与B的根结点的值一样的结点R
第二步再判断树A中以R为根结点的子树是不是包含树B一样的结构*/
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
class Solution {
public:
    bool DoesTree1hasTree2(TreeNode *tree1, TreeNode *tree2)
    {
    	if(tree2 == NULL) return true;
    	if(tree1 == NULL) return false;
    	if(tree1->val != tree2->val) return false;
    	return DoesTree1hasTree2(tree1->left, tree2->left) && DoesTree1hasTree2(tree1->right, tree2->right);
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
    	bool result = false;
    	if(pRoot1 && pRoot2){
    		if(pRoot1->val == pRoot2->val){
    			result = DoesTree1hasTree2(pRoot1, pRoot2);
    		}
    		if(!result){
    			result = HasSubtree(pRoot1->left,pRoot2)|| HasSubtree(pRoot1->right,pRoot2);
    		}
    	}
    	return result;
    }
};