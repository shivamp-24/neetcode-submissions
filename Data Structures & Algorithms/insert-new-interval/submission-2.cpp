class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int nl = newInterval[0], nr = newInterval[1];
        // insert all intervals whose end point < nl
        int i = 0, n = intervals.size();
        while(i < n && intervals[i][1] < nl) {
            res.push_back(intervals[i]);
            i++;
        }

        // keep merging intervals till intervals[i][0] <= currEnd
        if(i < n && intervals[i][0] <= nr) {
            int currStart = min(intervals[i][0], nl), currEnd = max(intervals[i][1], nr);
            i++;
            while(i < n && intervals[i][0] <= currEnd) {
                currEnd = max(currEnd, intervals[i][1]);
                i++;
            }
            res.push_back({currStart, currEnd});
        } else {
            res.push_back(newInterval);
        }

        // remaining intervals as it is
        while(i < n) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};
