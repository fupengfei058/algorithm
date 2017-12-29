/*Combination Sum:Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> comb;
        combinationSum(candidates, target, res, comb, 0);
        return res;
    }
private:
    void combinationSum(vector<int> &cand, int target, vector<vector<int>> &res, vector<int> &comb, int begin) {
        if(!target){
        	res.push_back(comb);
        	return;
        }
        for(int i = begin; i != cand.size() && target >= cand[i]; ++i){
        	comb.push_back(cand[i]);
        	combinationSum(cand, target - cand[i], res, comb, i);
        	comb.pop_back();
        }
    }
};