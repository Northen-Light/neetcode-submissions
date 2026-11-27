class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& I, vector<int>& NI) {
        int n = I.size();
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            if (NI[1] < I[i][0]) {
                ans.push_back(NI);
                copy(begin(I) + i, end(I), back_inserter(ans));
                return ans;
            } else if (I[i][1] < NI[0]) {
                ans.push_back(I[i]);
            } else {
                NI[0] = min(I[i][0], NI[0]); 
                NI[1] = max(I[i][1], NI[1]); 
            }
        }

        ans.push_back(NI);

        return ans;
    }
};
