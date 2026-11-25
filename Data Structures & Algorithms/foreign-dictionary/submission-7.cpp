class Solution {
public:
    bool toposort(int root, vector<int> adj[], vector<int> &vis, vector<int> &ans) {
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

    string toposortHelper(vector<int> adj[]) {
        vector<int> vis(26, 0);
        vector<int> ans;
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

    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        vector<int> adj[26];
        vector<int> ans;
        for (int i = 0; i + 1 < n; i++) {
            bool gotDiff = false;
            int n = words[i].size();
            int m = words[i + 1].size();
            for (int j = 0; j < min(n, m); j++) {
                if (words[i][j] != words[i + 1][j]) {
                    adj[words[i][j] - 'a'].push_back(words[i + 1][j] - 'a');
                    gotDiff = true;
                    break;
                }
            }
            if (!gotDiff) {
                if (n > m) {
                    return "";
                }
            }
        }
        return toposortHelper(adj);
    }
};