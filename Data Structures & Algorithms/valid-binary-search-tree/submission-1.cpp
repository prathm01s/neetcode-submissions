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
    bool helper(TreeNode* root) {
        if (!root) return true;
        int mx = getMax(root->left);
        int mn = getMin(root->right);
        if (root->val > mx && root->val < mn) {
            return helper(root->left) && helper(root->right);
        } else {
            return false;
        }
    }
    int getMax(TreeNode* root) {
        if (!root) return INT_MIN;
        return max(root->val, max(getMax(root->left), getMax(root->right)));
    }
    int getMin(TreeNode* root) {
        if (!root) return INT_MAX;
        return min(root->val, min(getMin(root->left), getMin(root->right)));
    }
    bool isValidBST(TreeNode* root) {
        return helper(root);
    }
};
