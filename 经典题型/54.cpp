/*二叉树_二叉树的镜像
操作给定的二叉树，将其变换为源二叉树的镜像。
思路：改写中序遍历*/
#include <iostream>
#include <stack>
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
    void Mirror(TreeNode *pRoot) {
       if(pRoot == NULL) return;
       stack<TreeNode* > tmp;
       while(pRoot || !tmp.empty())
       {
           while(pRoot)
           {
               tmp.push(pRoot);
               pRoot = pRoot->left;
           }
           pRoot = tmp.top();
           tmp.pop();
           
           TreeNode* temp = pRoot->left;
           pRoot->left = pRoot->right;
           pRoot->right = temp;
           //本来此处应该访问右子树，因为交换改为访问左子树
           pRoot = pRoot->left;  
       }
    }
};