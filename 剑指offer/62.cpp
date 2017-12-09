/*如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。*/
class Solution {
public:
    vector <int> fl;//从小到大排序
    int count = 0;
    void Insert(int num)
    {
        auto it = fl.begin();
        while (it != fl.end())
        {
            if (num < *it) break;
            ++it;
        }
        fl.insert(it, num); //在迭代器it前面插入一个元素
        ++count;
    }
    double GetMedian()
    {
        if (count % 2 == 1)
            return fl[count /2];
        else
            return (fl[count / 2 - 1]+ fl[count / 2 ])/2.0;
    }
};