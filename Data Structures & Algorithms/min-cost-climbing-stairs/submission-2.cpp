class Solution {
// private:
//     vector<int> dp;
//     int findCost(int ind, vector<int> &cost) {
//         if(ind >= cost.size()) return 0;

//         if(dp[ind] != -1) return dp[ind];
//         return dp[ind] = cost[ind] + min(findCost(ind + 1, cost), findCost(ind + 2, cost));
//     }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // dp.assign(cost.size(), -1);
        // int way1 = findCost(0, cost);
        // dp.assign(cost.size(), -1);
        // int way2 = findCost(1, cost);
        // return min(way1, way2);

        // tabulation
        int n = cost.size();
        vector<int> dp(n+1);
        // dp[i] -> min cost to reach step i
        dp[0] = dp[1] = 0;
        for(int i=2; i<=n; i++) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }

        return dp[n];
    }
};
