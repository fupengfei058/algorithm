/*数组_循环有序数组最小值
对于一个有序循环数组arr，返回arr中的最小值。有序循环数组是指，有序数组左边任意长度的部分放到右边去，右边的部分拿到左边来
思路:如果子数组是普通升序数组，则A[left]<A[right]。对于循环升序数组，A[left]>A[right]*/
#include <iostream>
#include <vector>
using namespace std;
class MinValue {
	int getMin(vector<int> arr, int n) {
		int left = 0;
        int right = n-1;
        int mid = 0;
        while(left<right)
        {
            mid = (left+right)/2;
            if(arr[mid]<arr[right])
            {
               right = mid; 
            }
            else
            {
                left = mid+1;
            }
        }
       return arr[left];
	}
};