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
    unordered_map<int, int>mp;
    int solve(TreeNode* root) {
        if(root == NULL) return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        int a = root->val + left + right;
        mp[a]++;
        return a;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        solve(root);
        int maxi = INT_MIN;
        vector<int>ans;
        for(auto val : mp) {
            maxi = max(maxi, val.second);
        }
        for(auto val : mp) {
            if(val.second == maxi) {
                ans.push_back(val.first);
            }
        }
        return ans;
    }
};