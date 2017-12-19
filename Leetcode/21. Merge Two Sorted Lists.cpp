/*Merge Two Sorted Lists:Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.*/
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
	//递归
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val > l2->val){
        	ListNode* tmp = l2;
        	tmp->next = mergeTwoLists(l1, l2->next);
        	return tmp;
        }else{
        	ListNode* tmp = l1;
        	tmp->next = mergeTwoLists(l1->next, l2);
        	return tmp;
        }
    }
    //非递归
    ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
    	ListNode* result = new ListNode(0);
    	ListNode* p1 = l1;
    	ListNode* p2 = l2;
    	ListNode* tmp = result;
    	while(p1 && p2){
    		if(p1->val < p2->val){
    			tmp->next = p1;
    			p1 = p1->next;
    		}else{
    			tmp->next = p2;
    			p2 = p2->next;
    		}
    		tmp = tmp->next;
    	}
    	if(p1){
    		tmp->next = p1;
    		p1 = p1->next;
    	}
    	if(p2){
    		tmp->next = p2;
    		p2 = p2->next;
    	}
    	tmp = result;
    	result = tmp->next;
    	delete(tmp);
    	return result;
    }
};