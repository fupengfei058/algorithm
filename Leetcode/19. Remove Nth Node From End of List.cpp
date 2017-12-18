/*Remove Nth Node From End of List:Given a linked list, remove the nth node from the end of list and return its head.*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//要求只遍历一趟，需要两个指针p1、p2,p1先走n步，然后p1、p2一起走,直到p1到达链表结尾，此时p2就是需要删除的节点.
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	int cnt = n + 1;
        ListNode* p1 = head;
        while (p1 != NULL && cnt > 0) {
            p1 = p1->next;
            --cnt;
        }
        ListNode *tmp;
        if (cnt > 0) {
            tmp = head;
            head = head->next;
            delete tmp;
            return head;
        }
        ListNode *p2 = head;
        while (p1 != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        tmp = p2->next;
        p2->next = tmp->next;
        delete tmp;
        return head;
    }
};