/*给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。*/
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> re;
	    if (num.size() <= 0 || size > num.size()||size<=0) return re;
	    int n = num.size() + 1 - size;
	    for (int i = 0; i < n; ++i)
	    {
	        vector<int> tmp;
	        int max = num[i];
	        for (int j = i; j < i + size; ++j)
	        {
	            tmp.push_back(num[j]);
	            if (num[j]>max) max = num[j];
	        }
	        re.push_back(max);
	    }
	    return re;
    }
};