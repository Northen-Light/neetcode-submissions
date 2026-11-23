class Solution {
public:
    bool dfs(int node, int par, vector<int> adj[], vector<bool> &vis, int *count) {
        vis[node] = true;
        (*count)++;
        for (auto &v: adj[node]) {
            if (v != par) {
                if (vis[v]) return true;
                if (dfs(v, node, adj, vis, count)) return true;
            }
        }

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<bool> vis(n, false);

        for (auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int count = 0;
        bool hasCycle = false;

        hasCycle = dfs(0, -1, adj, vis, &count);

        if (count < n || hasCycle) return false;

        return true;
    }
};
