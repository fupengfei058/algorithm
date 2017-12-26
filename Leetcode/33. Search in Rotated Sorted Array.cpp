/*Search in Rotated Sorted Array:Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
You are given a target value to search. If found in the array return its index, otherwise return -1.*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
        	int mid = (left + right) / 2;
        	if(target == nums[mid]) return mid;
        	if(nums[mid] < nums[right]){
        		if(target > nums[mid] && target <= nums[right]){
        			left = mid + 1;
        		}else{
        			right = mid - 1;
        		}
        	}else{
        		if(target >= nums[left] && target < nums[mid]){
        			right = mid - 1;
        		}else{
        			left = mid + 1;
        		}
        	}
        }
        return -1;
    }
};