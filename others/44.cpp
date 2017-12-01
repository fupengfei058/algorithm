/*数组_最大间隔
给定整数数组A，求这N个数排序后的最大间隔，如1，7，14，9，4，13的最大间隔为4
思路:桶排序/hash映射
将N个数用间距(max-min)/(N-1)分成N-1个区间，则落在同一区间内的数不可能有最大间距，统计后一区间的最小值与前一个区间的最大值的差即可*/
#include <iostream>
using namespace std;
typedef struct tagSBucket
{
	bool bValid;
	int nMin;
	int nMax;
	tagSBucket():bValid(false){}
	void Add(int n)//将数n加入到桶中
	{
		if(!bValid)
		{
			nMin = nMax = n;
			bValid = true;
		}
		else
		{
			if(nMax<n)
				nMax = n;
			else if(nMin > n)
				nMin = n;
		}
	}
}SBucket;

int CalcMaxGap(const int* A,int size)
{
	SBucket* pBucket = new SBucket[size];
	int nMax = A[0];
	int nMin = A[0];
	int i;
	for(int i=1;i<size;i++)
	{
		if(nMax<A[i])
		    nMax = A[i];
		else if(nMin > A[i])
			nMin = A[i];
	}
	//依次将数据放入
	int delta = nMax-nMin;
	int nBucket;//某数应该在哪个桶中
	for(i=0;i<size;i++)
	{
		nBucket = (A[i]-nMin)*size/delta;
		if(nBucket>=size){
			nBucket = size-1;
		}
	    pBucket[nBucket].Add(A[i]);
	}
	//计算有效桶的间隔
	i = 0;//第一个肯定是有效的
	int nGap = 0;//最小间隔
	int gap;
	//i是前一个桶，j是后一个桶
	for(int j=1;j<size;j++)
	{
		if(pBucket[j].bValid)
		{
			gap = pBucket[j].nMin-pBucket[i].nMax;
			if(nGap < gap)
			{
			  nGap = gap;
			}
			i = j;
		}
	}
	return nGap;
}