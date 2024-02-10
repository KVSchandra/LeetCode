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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<long long>>adj;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, -1});
        while(!q.empty()){
            TreeNode*node = q.front().first;
            long long parentNode = q.front().second;
            q.pop();
            if(parentNode != -1){
                adj[parentNode].push_back(node->val);
                adj[node->val].push_back(parentNode);
            }
            if(node->left) q.push({node->left, node->val});
            if(node->right) q.push({node->right, node->val});
        }
        queue<long long>q1;
        q1.push(start);
        unordered_map<long long, bool>vis;
        vis[start] = 1;
        int count = 0;
        while(!q1.empty()){
            long long size = q1.size();
            count++;
            while(size--){
                long long node = q1.front();
                q1.pop();
                for(auto val : adj[node]){
                    if(!vis[val]){
                        vis[val] = 1;
                        q1.push(val);
                    }
                }
            }
        }
        return count - 1;
    }
};