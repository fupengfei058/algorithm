/*在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
    	if (pHead == NULL || pHead->next == NULL)
            return pHead;
        //先为链表创建一个头结点
        ListNode* p1 = new ListNode(0);
        p1->next = NULL;//p1的轨迹记录没有重复的节点
        ListNode* head = p1;
        ListNode* p2 = pHead;//p2用于遍历原链表，方便p1跳过重复的点
        while(p2){
            if(p2->next && p2->val == p2->next->val){
                while(p2->next && p2->val == p2->next->val){
                    p2 = p2->next;
                }
                p2 = p2->next;//p2跳过重复串中的最后一个重复节点
                //防止链表尾出现重复，p2==NUll，程序跳出while循环，而p1没有跳过尾部重复
                p1->next = p2;
            }
            else{//如果没有重复
                p1->next = p2;
                p1 = p2;
                p2 = p2->next;
            }
        }
        return head->next;//返回时要去除头节点
    }
};