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
    int sum = 0;
    void solve(TreeNode* root) {
        if(root == NULL) return;
        
        if((root->val)%2 == 0) {
            if(root->left) {
                if(root->left->left) sum += root->left->left->val;
                if(root->left->right) sum += root->left->right->val;
            }
            if(root->right) {
                if(root->right->left) sum += root->right->left->val;
                if(root->right->right) sum += root->right->right->val;
            }
        }
        solve(root->left);
        solve(root->right);
    }

    int sumEvenGrandparent(TreeNode* root) {
        solve(root);
        return sum;
    }
};