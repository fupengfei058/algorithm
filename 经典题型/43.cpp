/*数组_最大子数组和
给定一个数组A[0,...,N-1],求A的连续子数组，使得该子数组的和的最大，如数组1,-2,3,10,-4,7,2,-5,最大子数组:3,10,-4,7,2
思路::动态规划 最优子问题*/
#include <iostream>
using namespace std;
int MaxSubArray(const int* a,int size) {
	if(!a || size <= 0) return 0;
	int sum = a[0];
	int result = sum;
	for(int i = 1; i < size; i++){
		if(sum > 0){
			sum += a[i];
		}else{
			sum = a[i];
		}
		result = max(sum, result);
	}
	return result;
}