/*Search for a Range:Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int n = nums.size();
        int pos = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (pos == n || nums[pos] > target) {
            return res;
        }
        res[0] = pos;
        res[1] = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return res;
    }
};