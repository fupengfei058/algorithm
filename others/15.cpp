/*环形链表插值:有一个整数val，如何在节点值有序的环形链表中插入一个节点值为val的节点，并且保证这个环形单链表依然有序。
给定链表的信息，及元素的值A及对应的nxt指向的元素编号同时给定val，请构造出这个环形链表，并插入该值*/
/*思路：如果val大于头节点的值则更新头节点，如果是中间位置，则需要防止断链*/
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class InsertValue {
public:
	ListNode* insert(vector<int> A, vector<int> nxt, int val) {
    	ListNode* ret=new ListNode(val);
        if(A.size()==0){          
            //ret->next=ret;
            return ret;
        }
        ListNode* head=new ListNode(A[0]);
        ListNode* p=head;
        ListNode* tmp;
        for(int i=0;i<nxt.size()-1;i++){
            tmp=new ListNode(A[nxt[i]]);
            p->next=tmp;
            p=tmp;
        }
        //p->next=head;
         //如果val大于头节点的值则更新头节点
        //如果是尾部
        //如果是中间位置，则需要防止断链
        if(val<=head->val){
            ret->next=head;
            head=ret;
            return head;
        }
        else if(val>=p->val){
            p->next=ret;
            //ret->next=head;
            return head;
        }
        else{
            ListNode* front=head;
            ListNode* pnext=head->next;
            while(pnext!=NULL){
                if(front->val<=val && val<=pnext->val){
                    front->next=ret;
                    ret->next=pnext;
                    break;
                }
                front=front->next;
                pnext=pnext->next;
            }
            return head;
        }
	}
};