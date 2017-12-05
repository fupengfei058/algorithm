/*二叉树_二叉搜索树的第k个结点
思路：给定一颗二叉搜索树，请找出其中的第k大的结点。
例如， 
   5 
  / \ 
 3  7 
/\  /\ 
2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。*/
#include <iostream>
#include <vector>
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
   int count = 0;
public:
    TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
    {
        if(pRoot)
        {
            TreeNode* ret = KthNode(pRoot->left,k);
            if(ret) return ret;
            if(++count == k) return pRoot;
            ret = KthNode(pRoot->right,k);
            if(ret) return ret;
        }
        return NULL;
    }
};