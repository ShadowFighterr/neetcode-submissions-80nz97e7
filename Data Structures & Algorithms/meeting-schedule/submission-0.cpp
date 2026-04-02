/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
                return a.start < b.start;
            });
        for(int i = 0; i < intervals.size(); i++){
            if(i+1 < intervals.size()){
                Interval& A = intervals[i];
                Interval& B = intervals[i+1];
                if (B.start < A.end) return false;
            }
        }
        return true;
    }
};
