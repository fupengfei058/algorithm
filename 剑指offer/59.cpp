/*从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。*/
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
    vector<vector<int> > Print(TreeNode* pRoot) {
    	vector<vector<int> > res;
    	if(pRoot == NULL) return res;
    	vector<int> lineRes;
    	queue<TreeNode*> q;
    	TreeNode* tmp;
    	q.push(pRoot);
    	while(!q.empty()){
    		int low = 0, high = q.size();
    		while(low++ < high){
    			tmp = q.front();
	    		lineRes.push_back(tmp->val);
	    		q.pop();
	    		if(tmp->left) q.push(tmp->left);
	    		if(tmp->right) q.push(tmp->right);
    		}
    		res.push_back(lineRes);
    		lineRes.clear();
    	}
    	return res;
    }
};