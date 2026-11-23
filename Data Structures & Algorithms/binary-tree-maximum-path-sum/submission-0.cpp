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
    int maxPathSumHelper(TreeNode *root, int *value) {
        if (root == NULL) return 0;
        int left = maxPathSumHelper(root -> left, value);
        int right = maxPathSumHelper(root -> right, value);

        int maxPathSum = max(left + right + root -> val, 
                     max(left + root -> val, 
                     max(right + root -> val, root -> val)));

        *value = max(*value, maxPathSum);
        return max(root -> val, max(left + root -> val, right + root -> val));
    }

    int maxPathSum(TreeNode* root) {
        int value = INT_MIN;
        maxPathSumHelper(root, &value);
        return value;
    }   
};
