/*链表的k逆序:有一个单链表，请设计一个算法，使得每K个节点之间逆序，如果最后不够K个节点一组，则不调整最后几个节点。
例如链表1->2->3->4->5->6->7->8->null，K=3这个例子。
调整后为，3->2->1->6->5->4->7->8->null。因为K==3，所以每三个节点之间逆序，但其中的7，8不调整，因为只有两个节点不够一组。*/
/*思路一:可以使用栈存储k个节点，然后依次弹出
思路二:不使用栈，但是需要前一次调整后的最后一个节点指向下一组需要调整的最后一个节点*/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class KInverse {
public:
    ListNode* inverse(ListNode* head, int k) {
    	ListNode *p = head;
        ListNode *pre = NULL;
        ListNode *start = NULL;
		ListNode *pNext = NULL;
		unsigned int length = 1;
		while(p){
		  	length++;
		  	p = p->next;
		}
		if(length < k) return NULL;
        unsigned int count = 1;
        while(p != NULL)
        {
            pNext = p->next;
            if (count == k)
            {
                start = pre == NULL ? head : pre->next;
                head = pre == NULL ? p : head;
                resign(pre, start, p, pNext);
                pre = start;
                count = 0;
            }
            count++;
            p = pNext;
        }
        return head;
    }
    int resign(ListNode* left, ListNode* start, ListNode* end,ListNode* right) {
       	ListNode* pre = start;
       	ListNode* cur = start->next;
       	ListNode* pNext = NULL;
       	while(cur != right)
       	{
           	pNext = cur->next;
           	cur->next = pre;
           	pre = cur;
           	cur = pNext;
       	}
       	if(left != NULL)
       	{
           left->next = end;
       	}
        	start->next = right;
        	return 0;
    }
};