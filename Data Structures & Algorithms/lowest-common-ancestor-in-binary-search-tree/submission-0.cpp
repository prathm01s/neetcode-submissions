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

TreeNode* recurse(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;
    TreeNode* isLeft = recurse(root->left, p, q);
    TreeNode* isRight = recurse(root->right, p, q);
    if (isLeft && isRight) {
        return root;
    } else if (isLeft) {
        if (isLeft->val == p->val && root->val == q->val) {
            return root;
        } else if (isLeft->val == q->val && root->val == p->val) {
            return root;
        } else {
            return isLeft;
        }
    } else if (isRight) {
        if (isRight->val == p->val && root->val == q->val) {
            return root;
        } else if (isRight->val == q->val && root->val == p->val) {
            return root;
        } else {
            return isRight;
        }
    } else {
        if (root->val == p->val || root->val == q->val) {
            return root;
        } else {
            return nullptr;
        }
    }
    return nullptr;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return recurse(root, p, q);
    }
};
