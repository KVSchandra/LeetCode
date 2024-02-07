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
    void solve(TreeNode*root, int k, vector<int>&temp, vector<vector<int>>&ans){
        if(root == NULL) return;
        
        if(root->left == NULL && root->right == NULL){
            if(k == root->val) {
                temp.push_back(root->val); 
                ans.push_back(temp); 
                temp.pop_back();
            }
            return;
        }

        if(root->left){
            temp.push_back(root->val);
            solve(root->left, k-root->val, temp, ans);
            temp.pop_back();
        }
        if(root->right){
            temp.push_back(root->val);
            solve(root->right, k-root->val, temp, ans);
            temp.pop_back();
        }
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(root, targetSum, temp, ans);
        return ans;
    }
};