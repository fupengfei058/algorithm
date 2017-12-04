/*二叉树_根据前序和中序求中后序
思路:根据前序中序，构造二叉树，后序遍历二叉树;后序遍历最后一个结点即为根结点*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
如
前序：GDAFEMHZ
后序: ADEFGHMZ
*/
/*
根据前序中序，构造二叉树，后序遍历二叉树
*/
void inPre2Post(char* pInOrder, char* pPreOrder,int nLength,char *pPostOrder,int& nIndex)
{
    if(nLength <= 0)
		return;
	if(nLength == 1)
	{
	  pPostOrder[nIndex] = *pPreOrder;
	  nIndex++;
	  return;
	}
	char root = *pPreOrder;
	int nRoot = 0;
	for(;nRoot < nLength;nRoot++)
	{
	   if(pInOrder[nRoot] = root)
	   break;
	}
	inPre2Post(pInOrder,pPreOrder+1,nRoot,pPostOrder,nIndex);//递归左子树
	inPre2Post(pInOrder+nRoot+1,pPreOrder+nRoot+1,nLength-nRoot-1,pPostOrder,nIndex);//递归右子树
	pPostOrder[nIndex] = root;//后序遍历最后一个结点即为根结点
	nIndex++;
}