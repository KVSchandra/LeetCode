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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int maxi = 0;
        queue<pair<TreeNode*, long long>>q;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            int start = q.front().second;
            int end = q.back().second;
            while(size--){
                pair<TreeNode*, long long>p = q.front();
                q.pop();
                long long ind = p.second - start;
                if(p.first->left){
                    q.push({p.first->left, 2*ind + 1});
                }
                if(p.first->right){
                    q.push({p.first->right, 2*ind + 2});
                }
            }
            maxi = max(maxi, end - start + 1);
        }
        return maxi;
    }
};