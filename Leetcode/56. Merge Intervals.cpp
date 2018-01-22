/*Merge Intervals:Given a collection of intervals, merge all overlapping intervals.*/
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
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty()) return intervals;
        sort(intervals.begin(), intervals.end(), comp);
        vector<Interval> res;
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
        	Interval &p = res.back();
            if(intervals[i].start > p.end)res.push_back(intervals[i]);
            else if(intervals[i].end > p.end)p.end = intervals[i].end;
        }
        return res;
    }
private:
	static bool comp(Interval a, Interval b){
		return a.start < b.start;
	}
};