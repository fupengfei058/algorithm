/*一个链表中包含环，请找出该链表的环的入口结点。*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
    	ListNode* fast = pHead;
    	ListNode* slow = pHead;
    	while(fast!=NULL&&fast->next!=NULL){ //快指针一次走两步，慢指针一次走一步
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                ListNode*p=pHead;
                while(p!=slow){
                    p=p->next;
                    slow=slow->next;
                }
                return p;
            }
        }
        return NULL;
    }
};