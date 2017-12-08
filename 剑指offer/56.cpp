/*给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。*/
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(!pNode)  return pNode;
        //不存在右节点，找第一个父子关系为左的祖先节点中的父节点
        if(pNode->right == NULL){
            //是父节点的右节点说明父节点遍历过了
            while(pNode && pNode->next && pNode == pNode->next->right)  pNode = pNode->next;
            return pNode->next;
        }
        //存在右节点，找其最左
        pNode = pNode->right;
        while(pNode && pNode->left) pNode = pNode->left;
        return pNode;
    }
};