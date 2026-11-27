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
    pair<int,int> dfs(TreeNode *root, bool &isValid) {
        if (root == NULL) {
           return make_pair(INT_MIN, INT_MAX); 
        }

        pair<int,int> rootMinMax = make_pair(root -> val, root -> val);
        pair<int, int> leftMinMax = dfs(root -> left, isValid);
        pair<int, int> rightMinMax = dfs(root -> right, isValid);
       
        if (leftMinMax != make_pair(INT_MIN, INT_MAX)) {
            if (leftMinMax.second >= root -> val) {
                isValid = false;
                return make_pair(INT_MIN, INT_MAX); 
            }
            rootMinMax.first = leftMinMax.first;
        }

        if (rightMinMax != make_pair(INT_MIN, INT_MAX)) {
            if (root -> val >= rightMinMax.first) {
                isValid = false;
                return make_pair(INT_MIN, INT_MAX); 
            }
            rootMinMax.second = rightMinMax.second;
        }

        return rootMinMax;
    }
    bool isValidBST(TreeNode* root) {
        bool isValid = true;
        dfs(root, isValid);
        return isValid;
    }
};
