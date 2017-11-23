/*从上往下打印出二叉树的每个节点，同层节点从左至右打印。*/
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
    	vector<int> res;  
        if(!root)  
            return res;  
        deque<TreeNode*> queue;  
        queue.push_back(root);  
        while(!queue.empty()){  
            TreeNode * tmp = queue.front();  
            res.push_back(tmp->val);  
            if(tmp->left)  
                queue.push_back(tmp->left);  
            if(tmp->right)  
                queue.push_back(tmp->right);  
            queue.pop_front();  
        }  
        return res;
    }
};