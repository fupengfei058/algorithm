/*输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。*/
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
	vector<vector<int>> result;
    vector<int>temp;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root != NULL)
        findOnePath(root,expectNumber);
        return result;
    }
    void findOnePath(TreeNode* root,int expectNumber){
        temp.push_back(root->val);
        if(expectNumber - root->val==0 && root->right ==NULL && root->left == NULL)
            result.push_back(temp);
        if(root->left != NULL)findOnePath(root->left,expectNumber-root->val);
        if(root->right != NULL)findOnePath(root->right,expectNumber-root->val);
        temp.pop_back();
    }
};