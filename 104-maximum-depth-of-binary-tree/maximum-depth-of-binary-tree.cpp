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
    void dfs(TreeNode*root, int &ans, int height){
        if(root->left == NULL && root->right == NULL) {
            ans = max(ans, height);
            return;
        }
        if(root->left){
            dfs(root->left, ans, height+1);
        }
        if(root->right){
            dfs(root->right, ans, height+1);
        }
    }

    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0;
        dfs(root, ans, 0);
        return ans + 1;
    }
};