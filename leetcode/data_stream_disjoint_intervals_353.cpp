/***
Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.

For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:

[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7]
Follow up:
What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
    list<Interval> sumRanges;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    /*** time complexity - O(n) ***/
    void addNum(int val) {
        if(sumRanges.size() == 0 || sumRanges.back().end < val-1) {
            sumRanges.push_back(Interval(val, val));
            return;
        }
        if(sumRanges.front().start > val+1) {
            sumRanges.push_front(Interval(val, val));
            return;
        }
        if(sumRanges.back().end + 1 == val) {
            sumRanges.back().end = val;
            return;
        }
        
        for(list<Interval>::iterator it = sumRanges.begin(); it != sumRanges.end(); it++) {
            if((*it).start <= val && (*it).end >= val)
                return;
            if(val == (*it).start - 1) {
                (*it).start = val;
                if( it != sumRanges.begin() && (*prev(it)).end == val - 1) {
                    prev(it)->end = (*it).end;
                    sumRanges.erase(it);
                }
                return;
            }
            if((*it).end + 1 == val) {
                (*it).end = val;
                if(next(it) != sumRanges.end() && (*next(it)).start == val + 1) {
                    next(it)->start = (*it).start;
                    sumRanges.erase(it);
                }
                return;
            }
            
            if((it->end)+1 < val && val < (next(it)->start)-1) {
                sumRanges.insert(next(it), Interval(val, val));
            }
        }
    }
    
    /*** time complexity - O(n) ***/
    vector<Interval> getIntervals() {
        return vector<Interval>(sumRanges.begin(), sumRanges.end());
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
