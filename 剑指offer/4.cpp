/*输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        //判断前序遍历结果、中序遍历结果若为空，则该树不存在
        if (pre.empty() || vin.empty())
            return NULL;

        //定义迭代器，分别指向容器的首元素、尾元素
        vector<int>::iterator startpre = pre.begin();
        vector<int>::iterator endpre = pre.end() - 1;
        vector<int>::iterator startvin = vin.begin();
        vector<int>::iterator endvin = vin.end() - 1;

        //定义一个辅助函数ConstructCore来解决问题
        return ConstructCore(startpre,endpre,startvin,endvin);
    }

    //辅助函数ConstructCore，传入参数为四个迭代器
    TreeNode* ConstructCore(vector<int>::iterator startpre,vector<int>::iterator endpre,vector<int>::iterator startvin,vector<int>::iterator endvin){
        //指定当前根节点
        int rootval = *startpre;
        TreeNode* root = new TreeNode(rootval);
        //左（右）子树中是否仅剩一个元素了，如果是，则完成该元素定位
        if(startpre == endpre) {
            if (startvin == endvin && *startpre == *startvin) {
                return root;
            }
            else
                return nullptr;
        }

        //定位当前根节点在中序遍历序列中的位置
        vector<int>::iterator rootindex = startvin;
        while(rootindex != endvin && *rootindex != rootval)
            ++rootindex;

        //对左右子树进行分解迭代
        int length = rootindex - startvin;
        if(length > 0)
            root->left = ConstructCore(startpre+1,startpre+length,startvin,rootindex-1);
        if(endvin - rootindex > 0)
            root->right = ConstructCore(startpre+length+1,endpre,rootindex+1,endvin);
        return root;
    }
};