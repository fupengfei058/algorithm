/*实现一个算法，删除单向链表中间的某个结点，假定你只能访问该结点。*/
#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x):val, next(NULL){}
};
class Remove
{
public:
	bool remodeNode(ListNode *pNode)
	{
		if(pNode->next==NULL)
		{
			return false;
		}
		pNode->val = pNode->next->val;
		return true;
	}
};