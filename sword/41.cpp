/*输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
如果有多对数字的和等于S，输出两个数的乘积最小的。*/
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
    	vector<int> ret;
    	if(array.size() < 2 || sum <= 0) return ret;
        int i = 0;
        int j = array.size()-1;
        while(i < j){
        	int tmp = array[i] + array[j];
        	if(tmp == sum){
        		ret.push_back(i);
        		ret.push_back(j);
        		break;
        	}else if(tmp < sum){
        		i++;
        	}else{
        		j--;
        	}
        }
        return ret;
    }
};