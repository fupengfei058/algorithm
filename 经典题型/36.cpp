/*字符串_全排列*/
#include <iostream>
using namespace std;
/*
首先字符串中个各个字符出现在第一位，
然后除第一位之外的字符分别出现在第二位。
再让后除第一第二位的字符分别出现在第三位。依次类推。
每次操作完成后需要把字符串恢复到初始状态，方便后面的交替操作。
*/
void print(const int* a,int size)
{
	for(int i=0;i<size;i++)
		cout<<a[i]<<' ';
	cout<< endl;
}
void permutation(int* a,int size,int n)
{
	if(n==size-1)
	{
		print(a,size);
		return;
	}
	//重复字符
	int dup[256] = {0};
	for(int i=n;i<size;i++)
	{
		if(dup[a[i]]==1) continue;
		dup[a[i]] = 1;
		swap(a[i],a[n]);
		permutation(a,size,n+1);
		swap(a[i],a[n]);
	}
}
int main()
{
	int a[] ={1,2,3,4};
	permutation(a,sizeof(a)/sizeof(int),0);
	system("pause");
	return 0;
}