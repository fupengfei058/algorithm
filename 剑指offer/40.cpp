/*输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序*/
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int> > res;
		if(sum < 3) return res;
		int i = 1, j = 2, mid = (sum+1)/2, cur = i+j;
		while(i<j && j<=mid){
		    if(cur == sum){
		        vector<int> aRes;
		        for(int k=i; k<=j; k++){
		            aRes.push_back(k);
		        }
		        res.push_back(aRes);
		        cur += ++j;
		    }
		    else if(cur < sum){
		        cur += ++j;
		    }
		    else{
		        cur -= i++;
		    }
		}
		return res;
    }
};