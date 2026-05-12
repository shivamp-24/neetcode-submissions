class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, -1, 1, 0};
        int INF = 2147483647;
        int dist = 0;
        while(!q.empty()) {
            int sz = q.size();
            dist++;
            while(sz--) {
                auto it = q.front();
                q.pop();
                int cx = it.first, cy = it.second;

                for(int i=0; i<4; i++) {
                    int nx = cx + dx[i], ny = cy + dy[i];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny] == INF) {
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                        grid[nx][ny] = dist;
                    }
                }
            }
        }
    }
};
