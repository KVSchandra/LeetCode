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
    int maxLevelSum(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int maxi = INT_MIN;
        int count = 1;
        int ans;
        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            while(size--){
                TreeNode*temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                sum += temp->val;
            }
            if(maxi < sum){
                maxi = sum;
                ans = count;
            }
            count++;
        }
        return ans;
    }
};