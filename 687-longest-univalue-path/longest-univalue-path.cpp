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
    int solve(TreeNode*root, int &len) {
        if(root == NULL) return 0;
        int left = solve(root->left, len), right = solve(root->right, len);
        int lefth = 0, righth = 0;
        if(root->left && root->left->val == root->val) lefth =  1 + left;
        if(root->right && root->right->val == root->val) righth = 1 + right;
        len = max(len, lefth + righth);
        return max(lefth, righth);
    }

    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL) return 0;
        int len = 0;
        solve(root, len);
        return len;
    }
};