/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<TreeNode*> cur;
        vector<TreeNode*> next;

        if (root) {
            cur.push_back(root);
        }

        while (!cur.empty()) {
            vector<int> level;

            for (auto &v: cur) {
                level.push_back(v -> val);
                if (v -> left) next.push_back(v -> left);
                if (v -> right) next.push_back(v -> right);
            }

            ans.push_back(level);

            cur = next;
            next.clear();
        }

        return ans;
    }
};
