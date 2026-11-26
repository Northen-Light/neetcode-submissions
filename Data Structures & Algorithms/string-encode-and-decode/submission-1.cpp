class Solution {
public:

    string encode(vector<string>& strs) {
        string en = "";
        
        for (auto &str: strs) {
            en += to_string(str.length());
            en += '#';
            en += str;
        }

        return en;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int n = s.size();
        int index = 0;
        
        int start = 0;
        int cur = 0;
        int len = 0;

        while (cur < n) {
            start = cur;
            while (s[cur] != '#') {
                cur++;
            }

            len = stoi(s.substr(start, cur - start));
            
            start = cur + 1;
            cur = start + len;

            ans.push_back(s.substr(start, len));
        }


        return ans;
    }
};
