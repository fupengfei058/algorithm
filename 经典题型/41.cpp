/*数组_第一个缺失的整数
给定一个数组，找到从1开始，第一个不在数组中的正整数，如3，5，1，2，-3，7，14，8输出4
思路:将找到的元素放到正确的位置上，如果最终发现某个元素一直没有找到，则该元素即为所求
若A[i]=i,i加1，继续比较后面的元素;
若A[i]<i或A[i]>N或A[i]=A[A[i]]则丢弃A[i];
若A[i]>i,则将A[A[i]]和A[i]交换*/
#include <iostream>
using namespace std;
int FirstMissNumber(int* a,int size)
{
	a--;
    int i = 1;
    while(i <= size)
    {
		if(a[i] == i)
		{
			i++;
		}
		else if((a[i] < i)||(a[i]>size)||(a[a[i]] = a[i]))
		{
			a[i] = a[size];
			size--;
		}
		else
		{
			swap(a[a[i]],a[i]);
		}
    }
    return i;
}