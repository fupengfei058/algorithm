/*输入一个链表，反转链表后，输出链表的所有元素。*/
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
    ListNode* ReverseList(ListNode* pHead) {
    	ListNode* pre = NULL;
        ListNode* next = NULL;

        while(pHead != NULL){  
            next = pHead->next;//保存下一个节点
            pHead->next = pre;//反转尾链表的头结点
            pre = pHead;//改变头链表的头结点位置
            pHead = next;//跟新尾链表的头节点位置
        }
        
        return pre;
    }
};