/*数组_求最长可整合子数组的长度
先给出可整合数组的定义： 如果一个数组arr在排序之后，从最小值到最大值的顺序中，每相邻两个数之间差的绝对值都为1，则arr为可整合数组。 
例如： arr = {5，3，4，6，2}，再排序之后为：{2，3，4，5，6}，排序后符合每相邻两个数之间差的绝对值都为1，所以arr是可整合数组。
给定一个整形数组arr，请返回其中长度最大的可整合子数组的长度。
[5,0,1,2,4,3,9]，最长可整合子数组为[5,0,1,2,4,3]，所以返回6；[6,7,3,0,1,2,4,7]，最长可整合子数组为[3,0,1,2,4]，所以返回5。
要求：如果数组长度为N，时间复杂度请达到O(N^2)
思路：
可整合子数组没有重复(一旦出现就没有必要往右继续找了)
最大值-最小值+1 = 长度
不应该陷入题目中可整合子数组的定义中*/
class Solution {
public:
	/**
	 *	在数组中求长度最大的可整合子数组长度
	 *	arr：输入数组
	 *	返回：最大的可整合子数组的长度
	 */
	int getMaxLength(vector<int> arr, int len) {
        int res = 0;
        map<int,int>help;
        for(int i=0;i<len;i++)
        {
            int max=0x80000000;  
            int min=0x7fffffff;
            for(int j=i;j<len;j++)
            {
               if(help[arr[j]]!=0)
                {
                    break;
                }
                help[arr[j]]++;
                max = max>arr[j]?max:arr[j];
                min = min<arr[j]?min:arr[j];
                if(max-min == (j-i))
                {
                   res = res>(max-min+1)?res:(max-min+1);
                }
            }
            help.clear();
        }
       return res;
    }
};