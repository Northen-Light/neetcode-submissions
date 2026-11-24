class Solution {
public:
    void dfs(int target, int index, vector<int> &nums, vector<int> &c, vector<vector<int>> &ans) {
        if (target < 0 || index < 0) {
            return;
        } 
        if (target == 0) {
            ans.push_back(c);
            return;
        }
        
        c.push_back(nums[index]);
        dfs(target - nums[index], index, nums, c, ans);
        c.pop_back();

        dfs(target, index - 1, nums, c, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> c;

        dfs(target, n - 1, nums, c, ans);

        return ans;
    }
};

