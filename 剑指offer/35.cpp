/*输入两个链表，找出它们的第一个公共结点。*/
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int len1=GetListLength(pHead1);
        int len2=GetListLength(pHead2);
        ListNode* pLong=pHead1;
        ListNode* pShort=pHead2;
        int lenDiff=len1-len2;
        if(len1<len2){
            pLong=pHead2;
            pShort=pHead1;
            lenDiff=len2-len1;
        }
         
        for(int i=0;i<lenDiff;i++)
            pLong=pLong->next;
         
        while(pLong!=NULL && pShort!=NULL && pLong!=pShort){
            pLong=pLong->next;
            pShort=pShort->next;
        }
         
        ListNode* pFirstCommonNode=pLong;
        return pFirstCommonNode;
    }
    unsigned int GetListLength(ListNode* pHead){
        unsigned int len=0;
        while(pHead!=NULL){
            ++len;
            pHead=pHead->next;
        }
        return len;
    }
};