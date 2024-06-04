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
    unordered_map<TreeNode*, int> dp;
    int solve(TreeNode* root) {
        if(root == NULL) return 0;
        if(dp[root]) return dp[root];
        int pick = root->val;
        int notPick = 0;
        if(root->left) {
            pick += solve(root->left->left) + solve(root->left->right);
            notPick += 0 + solve(root->left);
        }
        if(root->right) {
            pick += solve(root->right->left) + solve(root->right->right);
            notPick += 0 + solve(root->right);
        }
        return dp[root] = max(pick, notPick);
    } 

    int rob(TreeNode* root) {
        if(root == NULL) return 0;
        return solve(root);
    }
};