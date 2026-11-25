class Solution {
public:
    bool toposort(int root, set<int> adj[], vector<int> &vis, vector<int> &ans) {
        vis[root] = 1;
        bool hasCycle = false;
        for (auto &v: adj[root]) {
            if (!vis[v]) {
                hasCycle |= toposort(v, adj, vis, ans);
            } else if (vis[v] == 1) {
                hasCycle |= true;
            }
        }
        ans.push_back(root);
        vis[root] = 2;
        return hasCycle;
    }
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        set<int> adj[26];
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                bool got = false;
                for (int k = 0, l = 0; k < min(words[i].size(), words[j].size()); k++, l++) {
                    if (words[i][k] != words[j][l]) {
                        adj[words[i][k] - 'a'].insert(words[j][l] - 'a');
                        got = true;
                        break;
                    }
                }
                if (!got) {
                    if (words[i].size() > words[j].size()) {
                        return "";
                    }
                }
            }
        }
        vector<int> vis(26, 0);
        for (int i = 0; i < 26; i++) {
            if (!vis[i]) {
                if (toposort(i, adj, vis, ans)) {
                    return "";
                }
            }
        }
        string res = "";
        while (!ans.empty()) {
            res += (ans.back() + 'a');
            ans.pop_back();
        }
        return res;
    }
};