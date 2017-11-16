/*有两个用链表表示的整数，每个结点包含一个数位。这些数位是反向存放的，也就是个位排在链表的首部。
编写函数对这两个整数求和，并用链表形式返回结果*/
#include<iostream>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Plus {
public:
    ListNode* plusAB(ListNode* a, ListNode* b) {
    	ListNode *head = new ListNode(-1);
    	ListNode *p = head;
    	ListNode *pa = a;
    	ListNode *pb = b;
    	int c = 0, sum, val1, val2;
    	while(pa != NULL || pb != NULL || c != 0){
    		val1 = pa == NULL ? 0 : pa->val;
	    	val2 = pb == NULL ? 0 : pb->val;
	    	sum = val1 + val2 + c;
	    	c = sum/10;
	    	ListNode *node = new ListNode(sum%10);
	    	p->next = node;
	    	p = node;
	    	pa = (pa == NULL ? NULL : pa->next);
            pb = (pb == NULL ? NULL : pb->next);
    	}
    	return head->next;
	}
};