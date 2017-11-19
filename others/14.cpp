/*判断是否回文链表*/
/*思路一：申请一个栈，将节点全部压入，遍历节点和弹出的节点对比
思路二：申请一个栈，用快指针和慢指针同时遍历，慢指针遍历时，将节点压入栈中，当快指针走完，慢指针在中间，整个调整过程实际上是把左边的节点折过来和右边的比较
思路三：找到中间节点，右边逆序调整，然后两头开始判断*/
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Palindrome {
public:
    bool isPalindrome(ListNode* pHead) {
    	
    }
}