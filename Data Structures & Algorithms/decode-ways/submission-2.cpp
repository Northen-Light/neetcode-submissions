class Solution {
public:
    int numWays(int idx, string &s, int n, vector<int> &dp) {
        if (idx == n) {
            return 1;
        }

        if (dp[idx] != -1) {
            return dp[idx];
        }

        int ans = 0;

        int first = s[idx] - '0';
        int second = idx + 1 < n ? s[idx + 1] - '0' : -1;
        int combined = (first > 0 && second != -1) ? first * 10 + second : 0;

        if (first > 0) {
            ans = numWays(idx + 1, s, n, dp);
        }

        if (combined > 0 && combined < 27) {
            ans += numWays(idx + 2, s, n, dp);
        } 

        return dp[idx] = ans;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return numWays(0, s, n, dp);
    }
};
