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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>v;
        if(root == NULL) return 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            long long sum = 0;
            int size = q.size();
            while(size--){
                TreeNode*temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                sum += temp->val;
            }
            v.push_back(sum);
        }
        if(v.size() < k) return -1;
        sort(v.begin(), v.end(), greater<long long>());
        return v[k-1];
    }
};