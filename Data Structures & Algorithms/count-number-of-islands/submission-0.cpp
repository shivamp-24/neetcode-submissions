class Solution {
private:
    vector<vector<int>> vis;
    int n, m;
    vector<int> dx = {-1, 0, 0, 1};
    vector<int> dy = {0, -1, 1, 0};

    void dfs(int cx, int cy, vector<vector<char>> &grid) {
        for(int i=0; i<4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '1' && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                dfs(nx, ny, grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        vis.assign(n, vector<int>(m, 0));

        int countIslands = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    countIslands++;
                    dfs(i, j, grid);
                }
            }
        }

        return countIslands;
    }
};
