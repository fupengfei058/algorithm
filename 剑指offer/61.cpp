/*给定一颗二叉搜索树，请找出其中的第k大的结点。
例如，  5 
	   / \ 
	   3  7 
	  /\  /\ 
	 2  4 6 8 中，按结点数值大小顺序第三个结点的值为4。*/
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
    TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
    {
        if(pRoot==NULL||k<=0) return NULL;
        vector<TreeNode*> vec;
        Inorder(pRoot,vec);
        if(k>vec.size())
            return NULL;
        return vec[k-1];
    }
    //中序遍历，将节点依次压入vector中
    void Inorder(TreeNode* pRoot,vector<TreeNode*>& vec)
    {
        if(pRoot==NULL) return;
        Inorder(pRoot->left,vec);
        vec.push_back(pRoot);
        Inorder(pRoot->right,vec);
    }
};