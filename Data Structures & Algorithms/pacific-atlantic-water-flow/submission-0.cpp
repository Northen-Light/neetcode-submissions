class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void dfs(int x, int y, vector<vector<int>>& H, vector<vector<bool>>& vis, vector<vector<bool>>& oc, int n, int m){
        vis[x][y] = true;
        oc[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int X = x + dx[i];
            int Y = y + dy[i];
            if (X >= 0 && X < n && Y >= 0 && Y < m && !vis[X][Y] && H[X][Y] >= H[x][y]) {
                dfs(X, Y, H, vis, oc, n, m);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& H) {
        int n = H.size();
        int m = H[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));
        vector<vector<bool>> pac(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            if (!vis[i][m - 1]) {
                dfs(i, m - 1, H, vis, atl, n, m);
            }
        }   
        for (int j = 0; j < m; j++) {
            if (!vis[n - 1][j]) {
                dfs(n - 1, j, H, vis, atl, n, m);
            }
        } 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vis[i][j] = false;
            }
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i][0]) {
                dfs(i, 0, H, vis, pac, n, m);
            }
        }   
        for (int j = 0; j < m; j++) {
            if (!vis[0][j]) {
                dfs(0, j, H, vis, pac, n, m);
            }
        } 

        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (atl[i][j] && pac[i][j]) {
                    res.push_back(vector<int>{i, j});
                }
            }
        }
        return res;
    }
};
