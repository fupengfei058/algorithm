/*Permutations II:Given a collection of numbers that might contain duplicates, return all possible unique permutations.*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		do {
			vector<int> v(nums.begin(), nums.end());
			ans.push_back(v);
		} while(next(nums));
		return ans;
    }
private:
   	bool next(vector<int> &v) {
		size_t n = v.size();
		int i;
		for (i = n - 2; i >= 0 && v[i] >= v[i + 1]; --i);
		if (i < 0) {
			reverse(v.begin(), v.end());
			return false;
		}
		int j;
		for (j = n - 1; j > i && v[j] <= v[i]; --j);
		swap(v[i], v[j]);
		reverse(v.begin() + i + 1, v.end());
		return true;
	}
};