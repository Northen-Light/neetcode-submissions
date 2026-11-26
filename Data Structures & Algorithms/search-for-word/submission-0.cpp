class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    bool dfs(int r, int c, int idx, int m, int n, int len, 
    vector<vector<char>>& board, string &word, vector<vector<bool>> &vis) {
        if (board[r][c] != word[idx]) {
            return false;
        }

        if (idx == (len - 1)) {
            return true;
        }

        vis[r][c] = true;


        for (int i = 0; i < 4; i++) {
            int R = r + dx[i];
            int C = c + dy[i];

            if (R >= 0 && R < m && C >= 0 && C < n) {
                if (!vis[R][C] && dfs(R, C, idx + 1, m, n, len, board, word, vis)) {
                    return true;
                }
            }

        }

        vis[r][c] = false;
        
        return false;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int len = word.length();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    for (int l = 0; l < n; l++) {
                        vis[k][l] = false;
                    }
                }
                if (dfs(i, j, 0, m, n, len, board, word, vis)) {
                    return true;
                }
            }
        }

        return false;
    }
};
