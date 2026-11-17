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
private:
    static bool comp(Interval &a, Interval &b) {
        return a.start < b.start;
    }
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.size() == 0) {
            return 0;
        } 
        priority_queue<int, vector<int>, greater<int>> ms;
        int rooms = 0;

        sort(intervals.begin(), intervals.end(), comp); 

        for (auto &v: intervals) {
            while (!ms.empty() && v.start >= ms.top()) {
                ms.pop();
            }
            ms.push(v.end);
            rooms = max(rooms, (int)ms.size());
        }

        return rooms;
    }
};
/* 
   
*/
