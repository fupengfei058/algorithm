/*连续子数组最大和*/
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
    	int start = 0;
		int answerstart = 0, answerend = 0;
		int endmax = array[0], answer = array[0];
		int n = array.size();
		for(int end=1;end<n;end++)
		{
			if(endmax > 0){
			   endmax += array[end];
			} 
			else
			{
			    endmax = array[end];
				start = end;
			}
			if (endmax > answer)
			{
			    answer = endmax;
				answerstart = start;
				answerend = end;
			}
		}
		return answer;
    }
};