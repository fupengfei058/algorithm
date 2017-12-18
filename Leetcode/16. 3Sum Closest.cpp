/*3Sum Closest:Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers. You may assume that each input would have exactly one solution.*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 3) return 0;
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        int i, j, k;
        int val;
        for (i = 0; i < n - 2; ++i) {
            j = i + 1;
            k = n - 1;
            while (j < k) {
                val = nums[i] + nums[j] + nums[k];
                if (abs(val - target) < abs(res - target)) {
                    res = val;
                }
                if (val < target) {
                    ++j;
                } else if (val > target) {
                    --k;
                } else {
                    return target;
                }
            }
        }
        return res;
    }
};