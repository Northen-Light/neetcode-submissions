class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS;
        int res = 1;

        for (auto &v: nums) {
            auto it = lower_bound(begin(LIS), end(LIS), v);

            if (it == LIS.end()) {
                LIS.push_back(v);
            } else {
                LIS[it - LIS.begin()] = v;
            }
            res = max(res, (int)LIS.size());
        }

        return res;
    }
};

// 9 0 4 3 4 2 7 3 4 5 6
//              (i)
// LIS : 0 2 3 4 5 6
