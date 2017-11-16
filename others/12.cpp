/*编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前*/
/*思路:小数链表和大数链表，最后完成后将两链表连接，注意头结点也有值*/
#include<iostream>
using namespace std;
struct ListNode
{
  int val;
  struct ListNode *next;
  ListNode(int x):val(x),next(NULL){}
};
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
    	ListNode *p = pHead;
    	ListNode *smallList = new ListNode(-1);
    	ListNode *bigList = new ListNode(-1);
    	ListNode *small = smallList;
    	ListNode *big = bigList;
    	while(p){
    		if(p->val < x){
    			small->next = p;
    			small = p;
    		}else{
    			big->next = p;
    			big = p;
    		}
    		p = p->next;
    	}
    	big->next = NULL;
    	small->next = bigList->next;
    	return smallList->next;
    }
};