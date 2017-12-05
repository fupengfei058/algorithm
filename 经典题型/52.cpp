/*二叉树_寻找错误结点
一棵二叉树原本是搜索二叉树，但是其中有两个节点调换了位置，使得这棵二叉树不再是搜索二叉树，请找到这两个错误节点并返回他们的值。保证二叉树中结点的值各不相同。
给定一棵树的根结点，请返回两个调换了位置的值，其中小的值在前。
思路：第一次降序的较大值 第二次降序的较小值*/
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
class FindErrorNode {
public:
    void mid(TreeNode* root,vector<int> &ret) {
    	if(root == NULL) return;
        mid(root->left, ret);
        ret.push_back(root->val);
        mid(root->right, ret);
    }
    vector<int> findError(TreeNode* root) {
    	vector<int> ret;
        mid(root, ret);
        int a = -1, b = -1;
        for(int i = 0; i < ret.size(); i++)
        {
            if(ret[i] < ret[i-1])
            {
                a = a == -1 ? ret[i-1] : a;
                b = ret[i];
            }
        }
        vector<int> res;
        res.push_back(b);
        res.push_back(a);
        return res;
    }
};