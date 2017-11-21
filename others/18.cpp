/*如何判断一个单链表是否有环？有环的话返回进入环的第一个节点的值，无环的话返回-1。如果链表的长度为N，请做到时间复杂度O(N)，额外空间复杂度O(1)。*/
/*思路：快指针一次跳两个，如果为NULL，则没有环
有环时，当快指针和慢指针相遇时，让快指针等于头节点， 一次遍历一个,慢指针一次遍历一个，在进入环的第一个节点再次相遇*/
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class ChkLoop {
public:
    int chkLoop(ListNode* head, int adjust) {
    	if(head == NULL || head->next == NULL) return -1;
    	ListNode* slow = head;
    	ListNode* fast = head;
    	while(slow && fast && fast->next){
    		slow = slow->next;
    		fast = fast->next->next;
    		if(slow == fast){
    			fast = head;
    			break;
    		}
    	}
    	if(fast == head){
    		while(fast != slow)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return fast->val;
    	}
    	return -1;
    }
};