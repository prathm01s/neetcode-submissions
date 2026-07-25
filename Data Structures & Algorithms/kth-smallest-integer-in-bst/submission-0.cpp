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
    TreeNode* parent(TreeNode* root, int val) {
        if (root->val == val) return nullptr;
        while (1) {
            if (val > root->val) {
                if (root->right) {
                    if (root->right->val == val) return root;
                    root = root->right;
                } else {
                    return nullptr;
                }
            } else if (val < root->val) {
                if (root->left) {
                    if (root->left->val == val) return root;
                    root = root->left;
                } else {
                    return nullptr;
                }
            }
        }
    }
    TreeNode* succ(TreeNode* root, int val) {
        TreeNode* succ = nullptr;
        while (1) {
            if (val == root->val) {
                if (root->right) {
                    root = root->right;
                    while (root->left) {
                        root = root->left;
                    }
                    return root;
                } else {
                    break;
                }
            } else if (val > root->val) {
                if (root->right) {
                    root = root->right;
                } else {
                    break;
                }
            } else if (val < root->val) {    
                succ = root;
                if (root->left) {
                    root = root->left;
                } else {
                    break;
                }
            }
        }
        return succ;
    }
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* temp1 = root;
        while (temp1->left) {
            temp1 = temp1->left;
        }
        k--;
        while (k--) {
            temp1 = succ(root, temp1->val);
        }
        return temp1->val;
    }
};
