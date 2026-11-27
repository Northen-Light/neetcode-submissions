class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& I, vector<int>& NI) {
        int n = I.size(); 
        vector<vector<int>> OI;
        vector<vector<int>> ans;
        bool isInserted = false;

        for (auto &v : I) {
            if (v[0] > NI[0]) {
                OI.push_back(NI);
                isInserted = true;
            }
            OI.push_back(v);
        } 

        if (!isInserted) {
            OI.push_back(NI);
        }

        int st = OI[0][0];
        int end = OI[0][1];

        for (int i = 1; i < OI.size(); i++) {
            if (end < OI[i][0]) {
                ans.push_back(vector<int>{st, end});
                st = OI[i][0];
                end = OI[i][1];
            } else {
                end = max(end, OI[i][1]);
            }
        }

        ans.push_back(vector<int>{st, end});

        return ans;
    }
};
