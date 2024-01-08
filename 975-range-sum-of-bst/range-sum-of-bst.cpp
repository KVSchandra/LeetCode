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
private:
int inorder(TreeNode*root,vector<int>&ans,int low,int high){
    if(root == NULL) return 0;
    
    if(root->left) inorder(root->left,ans,low,high);
    if(root->val >= low && root->val <= high) ans.push_back(root->val);
    if(root->right) inorder(root->right,ans,low,high);
    return accumulate(ans.begin(),ans.end(),0);
}


public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int>ans;
        return inorder(root,ans,low,high);
    }
};