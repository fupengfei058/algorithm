/*Add Two Numbers:You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode* head = new ListNode(-1);
    	ListNode* p = head;
    	ListNode* p1 = l1;
    	ListNode* p2 = l2;
    	int c = 0, val1, val2, sum;
        while(p1 || p2 || c != 0){
        	val1 = p1 == NULL ? 0 : p1->val;
        	val2 = p2 == NULL ? 0 : p2->val;
        	sum = val1 + val2 + c;
        	c = sum/10;
        	ListNode* node = new ListNode(sum%10);
        	p->next = node;
        	p = node;
        	p1 = p1 != NULL ? p1->next : NULL;
        	p2 = p2 != NULL ? p2->next : NULL;
        }
        return head->next;
    }
};