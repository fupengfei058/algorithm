/*Rotate List:Given a list, rotate the list to the right by k places, where k is non-negative.*/
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k <= 0){
            return head;
        }
        int count = 1;
        ListNode *pre = head,*cur;
        //统计节点个数，找到尾节点串成一个环
        while(pre->next != NULL){
            count++;
            pre = pre->next;
        }
        //串成一个环
        pre->next = head;
        //k可能大于链表长度
        k = k % count;
        int index = 1;
        pre = cur = head;
        //右移k位
        while(index <= (count - k)){
            pre = cur;
            cur = cur->next;
            index++;
        }
        //新的首尾节点
        pre->next = NULL;
        head = cur;
        return head;
    }
};