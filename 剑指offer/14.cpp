/*输入一个链表，输出该链表中倒数第k个结点。*/
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	int len = 0;
        ListNode* p = pListHead;
        while(p != NULL)  
        {
            len ++;
            p = p->next;
        }

        if(k > len) return NULL;
        int i = 1;
        p = pListHead;
        while( i < len-k+1)
        {
            p = p->next;
            i++;
        }
        return p;
    }
};