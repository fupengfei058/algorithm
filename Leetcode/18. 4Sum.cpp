/*4Sum:Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if(n < 4) return result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-3; ++i){
        	if (i > 0 && nums[i] == nums[i - 1])
				continue;
			vector<int> n(nums.begin() + i + 1, nums.end());
				vector<vector<int>> ret = threeSum(n, target - nums[i]); //基于3sum
				for (auto v : ret)
				{
					v.insert(v.begin(), nums[i]);
					result.push_back(v);
				}
        }
        return result;
    }
    vector<vector<int>> threeSum(vector<int> &num, int target) {
		vector<vector<int>> result;
		auto n = num.size();
		size_t i;
		for (i = 0; i < n; ++i) {
			if (i > 0 && num[i] == num[i - 1])
				continue;
			int a = num[i];
			int low = i + 1, high = n - 1;
			while (low < high) {
				int b = num[low];
				int c = num[high];
				if (a + b + c == target) {
					vector<int> v = {a, b, c};
					result.push_back(v);
					while (low + 1 < n && num[low] == num[low + 1]) low++;
					while (high - 1 >= 0 && num[high] == num[high - 1]) high--;
					low++;
					high--;
				} else if (a + b + c > target) {
					while (high - 1 >= 0 && num[high] == num[high - 1]) high--;
					high--;
				} else {
					while (low + 1 < n && num[low] == num[low + 1]) low++;
					low++;
				}
			}
		}
		return result;
	}
};