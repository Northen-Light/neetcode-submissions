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
    bool containsValue(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode **res) {
        if (root == NULL) return false;

        bool leftSubtree = containsValue(root -> left, p, q, res);
        bool rightSubtree = containsValue(root -> right, p, q, res);

        if (leftSubtree && rightSubtree) {
            *res = root;
        } 
        if (leftSubtree && (root == p || root == q)) {
            *res = root;
        }
        if (rightSubtree && (root == p || root == q)) {
            *res = root;
        }
        return leftSubtree || rightSubtree || (root == p || root == q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *res = NULL;
        containsValue(root, p, q, &res);
        return res;
    }
};
