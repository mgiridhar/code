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
    static bool compareInterval(const Interval &a, const Interval &b) {
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty())
            return intervals;
        sort(intervals.begin(), intervals.end(), compareInterval);
        int i=0;
        while(i<intervals.size()-1) {
            if(intervals[i].end >= intervals[i+1].start)
            {
                intervals[i].end = max(intervals[i].end, intervals[i+1].end);
                intervals.erase(intervals.begin()+i+1);
            }
            else
                i++;
        }
        return intervals;
    }
};