class Solution {
private:
    string delimiter = "•";
public:

    string encode(vector<string>& strs) {
        string en = "";
        for (auto &v: strs) {
            en += v;
            en += delimiter;
        }
        return en;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        size_t start = 0;
        size_t end = s.find(delimiter);

        while (end != string::npos) {
            ans.push_back(s.substr(start, end - start));
            start = end + delimiter.length();
            end = s.find(delimiter, start);
        }

        return ans;
    }
};
