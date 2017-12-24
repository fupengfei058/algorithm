/*Next Permutation:Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return;
        }
        int i;
        for (i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
        }
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int j;
        for (j = n - 1; j > i; --j) {
            if (nums[j] > nums[i]) {
                break;
            }
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};