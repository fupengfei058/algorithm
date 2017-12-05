/*二叉树_树上最远距离
从二叉树的节点A出发，可以向上或者向下走，但沿途的节点只能经过一次，当到达节点B时，路径上的节点数叫作A到B的距离。
对于给定的一棵二叉树，求整棵树上节点间的最大距离。 给定一个二叉树的头结点root，请返回最大距离。保证点数大于等于2小于等于500.
思路：
情况A: 路径经过左子树的最深节点，通过根节点，再到右子树的最深节点。
情况B: 路径不穿过根节点，而是左子树或右子树的最大距离路径，取其大者。*/
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

class LongestDistance {
public:
    int depth(TreeNode* root,int &dep)
    {
    	
    }
};