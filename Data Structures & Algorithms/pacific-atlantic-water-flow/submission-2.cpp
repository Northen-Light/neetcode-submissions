class Solution {
public:
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, 1, -1, 0};

    void dfs(int r, int c, int n, int m, vector<vector<int>>& H, vector<vector<bool>> &vis, vector<vector<bool>> &flow) {
        vis[r][c] = true;
        flow[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int R = r + dx[i];
            int C = c + dy[i];

            if (R >= 0 && R < n && C >= 0 && C < m && !vis[R][C] && H[r][c] <= H[R][C]) {
                dfs(R, C, n, m, H, vis, flow);
            }
        }

        vis[r][c] = false;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& H) {
        int n = H.size();
        int m = H[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            dfs(i, 0, n, m, H, vis, pac);
        }

        for (int j = 0; j < m; j++) {
            dfs(0, j, n, m, H, vis, pac);
        }

        for (int i = 0; i < n; i++) {
            dfs(i, m - 1, n, m, H, vis, atl);
        }

        for (int j = 0; j < m; j++) {
            dfs(n - 1, j, n, m, H, vis, atl);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pac[i][j] && atl[i][j]) {
                    ans.push_back(vector<int>{i, j});
                }
            }
        }

        return ans;
    }
};
