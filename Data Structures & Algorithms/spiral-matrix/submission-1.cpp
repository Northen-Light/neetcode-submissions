class Solution {
public:
    void solve(int r, int c, int m, int n, vector<vector<int>>& mat, vector<int> &ans) {
        if (r >= m || c >= n) {
            return;
        }
        for (int j = c; j < n; j++) {
            ans.push_back(mat[r][j]);
        }

        for (int i = r + 1; i < m; i++) {
            ans.push_back(mat[i][n - 1]);
        }

        if (r < (m - 1)) {
            for (int j = n - 2; j >= c; j--) {
                ans.push_back(mat[m - 1][j]);
            }
        }

        if (c < (n - 1)) {
            for (int i = m - 2; i > r; i--) {
                ans.push_back(mat[i][c]);
            }
        }

        solve(r + 1, c + 1, m - 1, n - 1, mat, ans);
    }

    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;

        solve(0, 0, m, n, mat, ans);
        return ans;
    }
};
