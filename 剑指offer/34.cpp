/*在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007*/
/*输入描述：
题目保证输入的数组中没有的相同的数字
数据范围：
	对于%50的数据,size<=10^4
	对于%75的数据,size<=10^5
	对于%100的数据,size<=2*10^5*/
class Solution {
public:
    long long nums = 0;
    int InversePairs(vector<int> data) {
        vector<int> temp=data;
        MSort(data, temp, 0, data.size()-1);
    //  cout << "nums:" << nums << endl;
        return nums % 1000000007;
    }

    void Merge(vector<int> &data, vector<int> &temp, int begin, int mid, int end)
    {
        int start = begin;//记录开始位置
        int left = begin;
        int right = mid + 1;
        while (left<=mid && right <=end)
        {
            if (data[left] < data[right])
            {
                temp[begin++] = data[left++];
            }
            else
            {
                temp[begin++] = data[right++];
                nums += mid - left + 1;
            }
        }
        while (left<=mid)
        {
            temp[begin++] = data[left++];
        }
        while (right <= end)
        {
            temp[begin++] = data[right++];
        }
        while (start<=end)
        {
            data[start] = temp[start];
            start++;
        }
    }

    void MSort(vector<int> &data, vector<int> &temp, int begin,int end)
    {
        int mid;
        if (begin < end)
        {
            mid = (begin + end) / 2;
            MSort(data, temp, begin, mid);
            MSort(data, temp, mid+1,end);
            Merge(data, temp, begin, mid, end);
        }
    }
};