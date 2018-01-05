/*Permutations:Given a collection of distinct numbers, return all possible permutations.*/
//交换法的思路是for(i = start to end)，循环中: swap (第start个和第i个)，递归调用(start+1)，swap back
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        permuteDFS(nums, 0, res);
        return res;
    }
    void permuteDFS(vector<int> &num, int start, vector<vector<int> > &res) {
        if (start >= num.size()) res.push_back(num);
        for (int i = start; i < num.size(); ++i) {
            swap(num[start], num[i]);
            permuteDFS(num, start + 1, res);
            swap(num[start], num[i]);
        }
    }
};