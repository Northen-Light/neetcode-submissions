class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        vector<int> sfre(52, 0);
        vector<int> tfre(52, 0);
        int left = 0;
        int right = 0;
        int len = INT_MAX;
        int st = 0;

        for (auto &ch: t) {
            if (ch >= 'A' && ch <= 'Z') {
                tfre[26 + ch - 'A']++;
            } else {
                tfre[ch - 'a']++;
            }
        }

        while (right < n) {
            if (s[right] >= 'A' && s[right] <= 'Z') {
                sfre[26 + s[right] - 'A']++;
            } else {
                sfre[s[right] - 'a']++;
            }

            right++;

            bool contains = true;

            for (int i = 0; i < 52; i++) {
                if (tfre[i] > sfre[i]) {
                    contains = false;
                    break;
                }
            }

            while (contains && left < right) {
                if (len >= (right - left)) {
                    len = right - left;
                    st = left;
                }

                if (s[left] >= 'A' && s[left] <= 'Z') {
                    sfre[26 + s[left] - 'A']--;
                } else {
                    sfre[s[left] - 'a']--;
                }

                left++;

                for (int i = 0; i < 52; i++) {
                    if (tfre[i] > sfre[i]) {
                        contains = false;
                        break;
                    }
                }
            }
        }

        return s.substr(st, len == INT_MAX ? 0 : len);
    }
};
