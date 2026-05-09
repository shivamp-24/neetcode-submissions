class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // unordered_map<int, int> mp;
        // for(int x: nums) mp[x]++;
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        // for(auto it: mp) {
        //     int el = it.first, cnt = it.second;
        //     pq.push({cnt, el});
        //     if(pq.size() > k) pq.pop();
        // }
        // vector<int> res;
        // while(!pq.empty()) {
        //     res.push_back(pq.top().second);
        //     pq.pop();
        // }
        // return res;

        // O(n) approach
        // using buckets
        // each index -> stores all values who occur index number of times
        int n = nums.size();
        unordered_map<int, int> mp;
        int maxi = 0;
        for(int x: nums) {
            mp[x]++;
            maxi = max(maxi, mp[x]);
        }
        vector<vector<int>> freq(maxi + 1);
        for(auto it: mp) {
            freq[it.second].push_back(it.first);
        }

        vector<int> res;
        for(int i=maxi; i>=1 && k>0; i--) {
            for(int x: freq[i]) res.push_back(x);
            k -= freq[i].size();
        }
        return res;
    }
};
