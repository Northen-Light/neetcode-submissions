class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int low = 0;
        int high = 0;
        int ans = 0;

        int mp[26];
        for (int i = 0; i < 26; i++) {
            mp[i] = 0;
        }

        while (high < n) {
            mp[s[high] - 'A']++;
            high++;

            int mxF = 0;
            for (int i = 0; i < 26; i++) {
                mxF = max(mxF, mp[i]);
            }

            while (((high - low) - mxF) > k) {
                mp[s[low] - 'A']--;
                low++;
                
                mxF = 0;
                for (int i = 0; i < 26; i++) {
                    mxF = max(mxF, mp[i]);
                }
            }

            ans = max(ans, (high - low));
        }

        return ans;
    }
};
