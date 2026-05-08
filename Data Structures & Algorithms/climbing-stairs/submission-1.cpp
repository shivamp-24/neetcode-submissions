class Solution {
public:
    vector<int> dp;
    int findAllWays(int curr, int n) {
        if(curr > n) return 0;
        if(curr == n) return 1;

        if(dp[curr] != -1) return dp[curr];

        return dp[curr] = findAllWays(curr + 1, n) + findAllWays(curr + 2, n);
    }
    int climbStairs(int n) {
        dp.assign(n, -1);
        return findAllWays(0, n);
    }
};
