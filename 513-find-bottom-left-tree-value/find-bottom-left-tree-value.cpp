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
    int bottomleft = 0;
    int lowestlevel = INT_MIN;
    void dfs(TreeNode*root, int level){
        if(level > lowestlevel){
            lowestlevel = level;
            bottomleft = root->val;
        }
        if(root->left) dfs(root->left, level + 1);
        if(root->right) dfs(root->right, level + 1);
    }

    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return bottomleft;
    }
};