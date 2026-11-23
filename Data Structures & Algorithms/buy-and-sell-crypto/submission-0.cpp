class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int ans = 0;
        for (int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            ans = max(ans, prices[i] - minPrice);
        }
        return ans;
    }
};
