class Solution {
// private:
//     vector<vector<int>> vis;
//     int n, m;
//     vector<int> dx = {-1, 0, 0, 1};
//     vector<int> dy = {0, -1, 1, 0};

//     void dfs(int cx, int cy, vector<vector<char>> &grid) {
//         for(int i=0; i<4; i++) {
//             int nx = cx + dx[i], ny = cy + dy[i];

//             if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '1' && !vis[nx][ny]) {
//                 vis[nx][ny] = 1;
//                 dfs(nx, ny, grid);
//             }
//         }
//     }

private:
    int n, m;
    vector<int> dx = {-1, 0, 0, 1};
    vector<int> dy = {0, -1, 1, 0};

    int findPar(int u, vector<vector<int>> &par) {
        int ui = u / m, uj = u % m;
        if(u == par[ui][uj]) return u;
        return par[ui][uj] = findPar(par[ui][uj], par);
    }

    void unionn(int u, int v, vector<vector<int>> &par) {
        int pu = findPar(u, par), pv = findPar(v, par);
        if(pu == pv) return;

        int pui = pu / m, puj = pu % m;
        par[pui][puj] = pv;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        // n = grid.size(), m = grid[0].size();
        // vis.assign(n, vector<int>(m, 0));

        // int countIslands = 0;
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<m; j++) {
        //         if(grid[i][j] == '1' && !vis[i][j]) {
        //             countIslands++;
        //             dfs(i, j, grid);
        //         }
        //     }
        // }

        // return countIslands;

        // DSU approach
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> par(n, vector<int>(m));
        int totalIslands = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                par[i][j] = i * m + j;
                if(grid[i][j] == '1') totalIslands++;
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1') {
                    int u = i * m + j;
                    for(int k=0; k<4; k++) {
                        int ni = i + dx[k], nj = j + dy[k];
                        if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '1') {
                            int v = ni * m + nj;
                            if(findPar(u, par) != findPar(v, par)) {
                                unionn(u, v, par);
                                totalIslands--;
                            }
                        }
                    }
                }
            }
        }

        return totalIslands;
    }
};
