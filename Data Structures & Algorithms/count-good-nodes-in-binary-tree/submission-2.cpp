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
void recurse(TreeNode* root, unordered_map<TreeNode*, int>& maxmap, int x) {
    if (!root) return;
    maxmap[root] = max(x, root->val);
    recurse(root->left, maxmap, maxmap[root]);
    recurse(root->right, maxmap, maxmap[root]);
}
int postorder(TreeNode* root, unordered_map<TreeNode*, int>& maxmap) {
    if (!root) return 0;
        int left = postorder(root->left, maxmap);
        int right = postorder(root->right, maxmap);
    if (root->val >= maxmap[root]) {
        return left+right+1;
    } else {
        return left+right;
    }
    return 0;
}

// trying to do it in a single pass
int helper(TreeNode* root, int mx) {
    if (!root) return 0;
    mx = max(mx, root->val);
    int left = helper(root->left, mx);
    int right = helper(root->right, mx);
    if (root->val >= mx) {
        return left+right+1;
    } else {
        return left+right;
    }
}


class Solution {
public:
    int goodNodes(TreeNode* root) {
        /*
        unordered_map<TreeNode*, int> maxmap;
        recurse(root, maxmap, root->val);
        return postorder(root, maxmap);
        */
        return helper(root, root->val);
    }
};
