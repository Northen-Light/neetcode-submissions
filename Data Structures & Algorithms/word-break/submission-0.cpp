class Solution {
public:
    bool dfs(int idx, int n, string &s, set<string> &st, vector<int> &dp) {
        if (idx == n) return true;
        if (dp[idx] != -1) return dp[idx];

        string word = "";
        bool splitPossible = false;

        for (int i = idx; i < n; i++) {
            word += s[i];

            if (st.find(word) != st.end()) {
                splitPossible |= dfs(i + 1, n, s, st, dp);
            }
        }

        return dp[idx] = splitPossible;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {    
        set<string> st;
        int n = s.size();
        vector<int> dp(n, -1);

        for (auto &v: wordDict) {
            st.insert(v);
        }

        return dfs(0, n, s, st, dp);
    }
};
