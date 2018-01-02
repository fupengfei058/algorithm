/*First Missing Positive:Given an unsorted integer array, find the first missing positive integer.*/
//交换数组元素，使得数组中第i位存放数值(i+1)。最后遍历数组，寻找第一个不符合此要求的元素，返回其下标。
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        while(i < n){
        	if(nums[i] != i+1 && nums[i] >= 1 && nums[i] <= n && nums[nums[i]-1] != nums[i]){
        		swap(nums[i], nums[nums[i]-1]);
        	}else{
        		i++;
        	}
        }
        for(i = 0; i < n; ++i){
        	if(nums[i] != i+1){
        		return i+1;
        	}
        }
        return n+1;
    }
};