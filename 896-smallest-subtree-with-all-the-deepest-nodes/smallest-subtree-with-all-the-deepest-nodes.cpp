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
    int getHeight(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    TreeNode* solve(TreeNode* root) {
        if(root == NULL) return root;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        if(left > right) {
            return solve(root->left);
        }
        else if(left < right) {
            return solve(root->right);
        }
        else {
            return root;
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solve(root);
    }
};