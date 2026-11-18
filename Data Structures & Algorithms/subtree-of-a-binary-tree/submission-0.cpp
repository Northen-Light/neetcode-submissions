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
    bool isSubtreeHelper(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL && subRoot == NULL) return true;
        if (root == NULL || subRoot == NULL) return false;

        if (root -> val == subRoot -> val) {
            bool left = isSubtreeHelper(root -> left, subRoot -> left);
            bool right = isSubtreeHelper(root -> right, subRoot -> right);
            return left && right;
        }
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) return false;

        bool isParentEqual = isSubtreeHelper(root, subRoot);

        bool isLeftEqual = isSubtree(root -> left, subRoot);
        bool isRightEqual = isSubtree(root -> right, subRoot); 

        return isParentEqual || isLeftEqual || isRightEqual;
    }
};
