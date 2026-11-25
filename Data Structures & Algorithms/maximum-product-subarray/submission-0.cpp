class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];
        int mn = nums[0];
        int ans = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] >= 0) {
                mx = max(mx * nums[i], nums[i]);
                mn = min(mn * nums[i], nums[i]);
            } else {
                int prevMx = mx;
                mx = max(mn * nums[i], nums[i]);
                mn = min(prevMx * nums[i], nums[i]);
            }

            ans = max(ans, mx);
        }

        return ans;
    }
};
// mx
// mn
// +, mx * v, v ; mx = max(mx * v, v) , mn = min(mn * v, v)  
// -, mn * v, v ; mx = max(mn * v, v),  mn = min(mx * v, v)

// ans = max(ans, mx)
