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
    int inorder(TreeNode *root, int k, int &value) {
        if (root == NULL) return 0;

        int left = inorder(root -> left, k, value);
        if (k == (left + 1)) value = root -> val;
        int right = inorder(root -> right, k - (left + 1), value);

        return left + right + 1;
    }

    int kthSmallest(TreeNode* root, int k) {
        int value;
        inorder(root, k, value);
        return value;
    }
};
