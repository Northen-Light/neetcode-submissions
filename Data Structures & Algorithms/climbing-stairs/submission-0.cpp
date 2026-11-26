class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        } else {
            int secondLast = 1;
            int last = 1;
            int cur;
            
            for (int i = 2; i <= n; i++) {
                cur = last + secondLast;
                secondLast = last;
                last = cur;
            }

            return cur;
        }
    }
};
