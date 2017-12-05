/*查找和排序_查找和为定值的两个数
思路：两头扫描*/
#include <iostream>
#include <algorithm>
using namespace std;
bool TwoSum(int* arr,int size,int sum,int& a,int& b)
{
   sort(arr,arr+size);
   int begin = 0;
   int end = size-1;
   int curSum;
   bool isFind = false;
   while(begin<end)
   {
      curSum = arr[begin]+arr[end];
	  if(curSum>sum)
	  {
	    end--;
	  }
	  else if(curSum<sum)
	  {
	    begin++;
	  }
	  else
	  {
	     isFind = true;
		 a = arr[begin];
		 b = arr[end];
		 break;
	  }
   }
   return isFind;
}