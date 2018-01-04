/*Jump Game II:Given an array of non-negative integers, you are initially positioned at the first index of the array.*/
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int reach = nums[0];
        int lastreach = 0;
        int step = 0;
        
        for (int i = 1; i <= reach && i < nums.size(); i++) {
            if (i > lastreach) {
                step++;
                lastreach = reach;
            }
            reach = max(reach, i+nums[i]);
        }
        if (reach < nums.size()-1) return 0;
        return step;
    }
};