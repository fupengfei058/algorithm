/*输入一个链表，从尾到头打印链表每个节点的值。*/
/** 
*  struct ListNode { 
*        int val; 
*        struct ListNode *next; 
*        ListNode(int x) : 
*              val(x), next(NULL) { 
*        } 
*  }; 
*/  
class Solution {  
public:  
    vector<int> printListFromTailToHead(ListNode* head) {  
        vector<int> re;  
        if(head==NULL)  
            return re;  
        stack<int> tmp;  
        while(head!=NULL){  
            tmp.push(head->val);  
            head=head->next;  
        }  
        while(!tmp.empty()){  
            re.push_back(tmp.top());  
            tmp.pop();  
        }  
        return re;  
    }  
};