/*输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）*/
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
    	if(pHead==NULL)return pHead;
        //每个节点分别拷贝一个在其后面，然后让原来的和拷贝random指向相对应的节点,最后分离
        RandomListNode *p = pHead;
        RandomListNode *pnext = NULL;
        //拷贝
        while(p != NULL)
        {
            pnext = p->next;
            p->next = new RandomListNode(p->label);
            p->next->next = pnext;
            p = pnext;
        }
        //每次各拿原始的和拷贝的节点一个，进行random指针指向操作
        RandomListNode *cp = NULL ;
        p = pHead;
        while(p != NULL)
        {
            cp =  p->next;
            pnext =  p->next->next;
            cp->random = p->random != NULL ? p->random->next : NULL;
            p = pnext;
        }
        //分离
        RandomListNode *res = pHead->next;
        p = pHead;
        while (p != NULL)
        {
            cp = p->next;
            pnext = p->next->next;
            p->next = pnext;
            cp->next = pnext != NULL ? pnext->next: NULL;
            p = pnext;
        }
        return res;
    }
};