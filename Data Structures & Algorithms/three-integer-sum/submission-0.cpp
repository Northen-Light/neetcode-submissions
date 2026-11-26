class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>> ans;
        int n = nums.size();

        int i = 0;

        while(i < n - 2) {
            int target = -nums[i];
            int low = i + 1;
            int high = n - 1;

            while (low < high) {
                int sum = nums[low] + nums[high];

                if (sum == target) {
                    ans.push_back(vector<int>{nums[i], nums[low], nums[high]});

                    low++;
                    high--;

                    while (nums[low] == nums[low - 1] && low < high) {
                        low++;
                    }

                    while (nums[high] == nums[high + 1] && low < high) {
                        high--;
                    }

                } else if (sum < target) {
                    low++;
                } else {
                    high--;
                }
            }
            i++;

            while (nums[i] == nums[i - 1] && i < (n - 2)) {
                i++;
            }
        }

        return ans;
    }
};
