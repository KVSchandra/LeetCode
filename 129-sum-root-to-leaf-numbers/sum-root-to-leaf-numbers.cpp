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
    int solve(TreeNode*root, int sum){
        if(root->left == NULL && root->right == NULL) return sum;
        int ans = 0;
        if(root->left) ans += solve(root->left, sum*10 + root->left->val);      
        if(root->right) ans += solve(root->right, sum*10 + root->right->val);
        return ans;
    }

    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        return solve(root, root->val);
    }
};