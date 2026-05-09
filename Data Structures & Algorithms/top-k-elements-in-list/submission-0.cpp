class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int x: nums) mp[x]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for(auto it: mp) {
            int el = it.first, cnt = it.second;
            pq.push({cnt, el});
            if(pq.size() > k) pq.pop();
        }
        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
