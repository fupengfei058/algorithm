/*Insert Interval:Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        auto itr = intervals.begin();
        for (; itr != intervals.end() && newInterval.end >= itr->start; itr++)
        {
            if (canMerge(*itr, newInterval))
            {
                *itr = merge(*itr, newInterval);
                
                // 检查后面的区间是否可以合并进来。
                auto itr2 = itr + 1;
                for (; itr2 != intervals.end(); itr2++)
                {
                    if (canMerge(*itr, *itr2))
                    {
                        *itr = merge(*itr, *itr2);
                    }
                    else
                    {
                        break;
                    }
                }
                intervals.erase(itr + 1, itr2);
                return intervals;
            }
        }
        
        // 如果newInterval不能跟任何一个已有的区间合并，那就把它插入数组的合适位置。
        // 所谓合适的位置，就是插入第一个比它的start大的区间前面。
        intervals.insert(itr, newInterval);
        return intervals;
    }
private:
    bool canMerge(const Interval &i1, const Interval &i2)
    {
        if (i1.start <= i2.start)
        {
            return i2.start <= i1.end;
        }
        else
        {
            return canMerge(i2, i1);
        }
    }
    
    Interval merge(const Interval &i1, const Interval &i2)
    {
        if (i1.start <= i2.start)
        {
            return Interval(i1.start, max(i1.end, i2.end));
        }
        else
        {
            return merge(i2, i1);
        }
    }
};