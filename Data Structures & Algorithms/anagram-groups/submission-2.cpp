class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {    
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> group;

        for (auto &str: strs) {
            string key = str;
           
            sort(begin(key), end(key));
           
            if (mp.find(key) != mp.end()) {
                mp[key].push_back(str);
            } else {
                mp[key] = { str };
            }
        }

        for (auto &v: mp) {
            vector<string> anag;

            for (auto &str: v.second) {
                anag.push_back(str);
            }

            group.push_back(anag);
        }

        return group;
    }
};
