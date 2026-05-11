class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        for(auto it: points) {
            int x = it[0], y = it[1];
            int dist = x*x + y*y;

            pq.push({dist, it});
            if(pq.size() > k) pq.pop();
        }
        vector<vector<int>> res;
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
