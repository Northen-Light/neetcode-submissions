class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n, false);
        
        vis[0] = true;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                break;
            }
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j < n) {
                    vis[i + j] = true;
                }
            }
        }

        return vis[n - 1];
    }
};
