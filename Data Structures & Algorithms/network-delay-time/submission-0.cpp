class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it: times) {
            adj[it[0] - 1].push_back({it[1] - 1, it[2]});
        }

        queue<pair<int, int>> q;
        // {time, node}
        q.push({0, k - 1});
        vector<int> dist(n, 1e9);
        dist[k - 1] = 0;

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            int u = it.second, cd = it.first;

            for(auto [v, wt]: adj[u]) {
                if(cd + wt < dist[v]) {
                    dist[v] = cd + wt;
                    q.push({dist[v], v});
                }
            }
        }
        int minTime = 0;
        for(int x: dist) {
            if(x == 1e9) return -1;
            minTime = max(minTime, x);
        }

        return minTime;
    }
};
