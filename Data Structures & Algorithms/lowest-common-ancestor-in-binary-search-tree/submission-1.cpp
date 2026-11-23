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
private:
    TreeNode *res = NULL;

    bool containsValue(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == NULL) return false;

        bool leftSubtree = containsValue(root -> left, p, q);
        bool rightSubtree = containsValue(root -> right, p, q);

        if (leftSubtree && rightSubtree) {
            res = root;
        } 
        if (leftSubtree && (root == p || root == q)) {
            res = root;
        }
        if (rightSubtree && (root == p || root == q)) {
            res = root;
        }
        return leftSubtree || rightSubtree || (root == p || root == q);
    }

public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        containsValue(root, p, q);
        return res;
    }
};
