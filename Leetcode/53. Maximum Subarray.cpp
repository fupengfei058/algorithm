/*Maximum Subarray:Find the contiguous subarray within an array (containing at least one number) which has the largest sum.*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int sum = nums[0];
        int result = sum;
        for(int i = 1; i < nums.size(); ++i){
        	if(sum > 0){
        		sum += nums[i];
        	}else{
        		sum = nums[i];
        	}
        	result = max(sum, result);
        }
        return result;
    }
};