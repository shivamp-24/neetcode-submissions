class Solution {
private:
    int n, m;
    vector<vector<int>> vis;
    vector<int> dx = {-1, 0, 0, 1};
    vector<int> dy = {0, -1, 1, 0};

    int dfs(int cx, int cy, vector<vector<int>> &grid) {
        vis[cx][cy] = 1;
        int count = 1;
        for(int i=0; i<4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny]) {
                count += dfs(nx, ny, grid);
            }
        }
        return count;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vis.assign(n, vector<int>(m, 0));

        int maxi = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] && !vis[i][j]) {
                    maxi = max(maxi, dfs(i, j, grid));
                }
            }
        }
        return maxi;
    }
};
