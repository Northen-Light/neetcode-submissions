class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for (auto &v: nums) {
            mp[v]++;
        }
        vector<pair<int,int>> fre;
        for (auto it: mp) {
            fre.push_back(make_pair(it.second, it.first));
        }
        sort(rbegin(fre), rend(fre));
        vector<int> res;
        for (int i = 0; i < min((int)fre.size(), k); i++) {
            res.push_back(fre[i].second);
        }
        return res;
    }
};
