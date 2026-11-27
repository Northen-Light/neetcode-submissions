class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();    
        vector<int> dp(n, 0);
        int ans = nums[0];

        for (int i = 0; i < n - 1; i++) {
            dp[i] = max(i > 0 ? dp[i - 1] : 0, nums[i] + (i > 1 ? dp[i - 2] : 0));
            ans = max(ans, dp[i]);
        }

        for (auto &v: dp) {
            v = 0;
        }

        for (int i = 1; i < n; i++) {
            dp[i] = max(i > 0 ? dp[i - 1] : 0, nums[i] + (i > 1 ? dp[i - 2] : 0));
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
