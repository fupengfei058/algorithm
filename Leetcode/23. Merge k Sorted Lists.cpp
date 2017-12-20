/*Merge k Sorted Lists:Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.*//**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//每次从lists中取出两个链表归并，然后把归并的结果压入lists中，直到只有一个链表为止。
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
		while (lists.size() > 1) {
			lists.push_back(mergeTwoLists(lists[0], lists[1]));
			lists.erase(lists.begin());
			lists.erase(lists.begin());
		}
		return lists.front();
    }
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
};