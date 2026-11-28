class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {    
        int n = strs.size();
        vector<vector<int>> freq(n, vector<int>(26, 0));
        map<vector<int>, vector<string>> mp;
        vector<vector<string>> ans;

        for (int i = 0; i < strs.size(); i++) {
            for (auto &ch: strs[i]) {
                freq[i][ch - 'a']++;
            }

            if (mp.find(freq[i]) != mp.end()) {
                mp[freq[i]].push_back(strs[i]);
            } else {
                mp[freq[i]] = vector<string> {strs[i]};
            }
        }

        for (auto &v: mp) {
            vector<string> anagrams;
            for (auto &str: v.second) {
                anagrams.push_back(str);
            }
            ans.push_back(anagrams);
        }
        
        return ans;
    }
};
