/*Search Insert Position:Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.You may assume no duplicates in the array.*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int s = 0, t = nums.size() - 1;
        while(s <= t){
        	int mid = (s + t) >> 1;
        	if(nums[mid] == target) return mid;
        	if(nums[mid] > target){
        		t = mid - 1;
        	}else{
        		s = mid + 1;
        	}
        }
        return s;
    }
};