class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        
        int i = 0;

        while (i < n) {
            if (newInterval[1] < intervals[i][0]) {
                ans.push_back(newInterval);
                while (i < n) {
                    ans.push_back(intervals[i]);
                    i++;
                }
                return ans;
            } else if (intervals[i][1] < newInterval[0]) {
                ans.push_back(intervals[i]);
            } else {
                int st = min(intervals[i][0], newInterval[0]); 
                int end = max(intervals[i][1], newInterval[1]); 
                newInterval = vector<int> {st, end};
            }

            i++;
        }

        ans.push_back(newInterval);

        return ans;
    }
};
