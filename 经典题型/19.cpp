/*现在有两个无环单链表，若两个链表的长度分别为m和n，请设计一个时间复杂度为O(n + m)，额外空间复杂度为O(1)的算法，判断这两个链表是否相交*/
/*思路 遍历两个链表得到长度，然后长链表先走差值，一样长时，再同步走，会同时到达相遇节点。*/
#include<iostream>
using namespace std;
//遍历两个链表得到长度，然后长链表先走差值，一样长时，再同步走，会同时到达相遇节点。
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class CheckIntersect {
public:
    bool chkIntersect(ListNode* headA, ListNode* headB) {
    	ListNode* p1 = headA;
    	ListNode* p2 = headB;
    	unsigned int length1 = 0;
    	unsigned int length2 = 0;
    	while(p1)
        {
            p1 = p1->next;
            length1++;
        }
         while(p2)
        {
            p2 = p2->next;
            length2++;
        }
        p1 = headA;
        p2 = headB;
        if(length1 >= length2){
        	unsigned int tmp = length1 - length2;
        	while(tmp--){
        		p1 = p1->next;
        	}
        }else{
        	unsigned int tmp = length2 - length1;
        	while(tmp--){
        		p2 = p2->next;
        	}
        }
        while(p1 && p2){
        	if(p1 == p2){
        		return true;
        	}
        	p1 = p1->next;
        	p2 = p2->next;
        }
        return false;
    }
};