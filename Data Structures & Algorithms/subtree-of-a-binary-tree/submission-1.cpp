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
    bool isSubtreeEqual(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL && subRoot == NULL) return true;
        if (root == NULL || subRoot == NULL) return false;

        if (root -> val == subRoot -> val) {
            bool left = isSubtreeEqual(root -> left, subRoot -> left);
            bool right = isSubtreeEqual(root -> right, subRoot -> right);
            return left && right;
        }
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) return false;

        bool current = isSubtreeEqual(root, subRoot);

        bool left = isSubtree(root -> left, subRoot);
        bool right = isSubtree(root -> right, subRoot); 

        return current || left || right;
    }
};
