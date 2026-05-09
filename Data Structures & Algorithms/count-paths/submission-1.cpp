class Solution {
private:
    vector<int> dx = {0, 1};
    vector<int> dy = {1, 0};
    vector<vector<int>> dp;
    int findAllWays(int cx, int cy, int n, int m) {
        if(cx == n-1 && cy == m-1) return 1;

        if(dp[cx][cy] != -1) return dp[cx][cy];
        int ways = 0;
        for(int i=0; i<2; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                ways += findAllWays(nx, ny, n, m);
            }
        }

        return dp[cx][cy] = ways;
    }
public:
    int uniquePaths(int n, int m) {
        dp.assign(n, vector<int>(m, -1));
        return findAllWays(0, 0, n, m);
    }
};
