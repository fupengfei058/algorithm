/*二叉树_二叉查找树判断
给定整数数组，判断该数组有无可能是一颗二叉查找树后序遍历的结果.假定数组中没有重复元素
思路:由于后序遍历的最后一个元素为根结点，根据该结点将数组分成前后两段,使得前半段都小于根结点，后半段反之*/
#include <iostream>
using namespace std;
bool canPostOrder(const int *a,int size)
{
  int left = 0;
  int root = a[size-1];
  for(int i=0;i<size;i++)
  {
	if(a[i] > root) break;
     left++;
  }
  int right =size-2;
  while(right>=0)
  {
	if(a[right] < root) break;
     right--;
  }
  if(left != right+1)
  {
     return false;
  }
  return canPostOrder(a,left) 
	  && canPostOrder(a+left,size-left-1);
}
int main(int argc,char* argv[])
{
	int a[] ={1,2,5,4,3};
	bool b = canPostOrder(a,sizeof(a)/sizeof(int));
	cout<<b<<endl;
	return 0;
}