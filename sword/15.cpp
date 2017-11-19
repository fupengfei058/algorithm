/*输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。*/
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        ListNode* newList = new ListNode(0);
        ListNode* cur = newList;
        while(p1 && p2){
        	if(p1->val <= p2->val){
        		cur->next = p1;
        		p1 = p1->next;
        		cur = cur->next;
        	}else{
        		cur->next = p2;
        		p2 = p2->next;
        		cur = cur->next;
        	}
        	// cur->next = NULL;
        }
        if(p1){
        	cur->next = p1;
        }
        if(p2){
        	cur->next = p2;
        }
        return newList->next;
    }
};