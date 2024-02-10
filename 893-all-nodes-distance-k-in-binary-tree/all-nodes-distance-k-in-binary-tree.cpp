/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        unordered_map<TreeNode*, bool>vis;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*node = q.front();
            q.pop();
            if(node->left){
                parent_track[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent_track[node->right] = node;
                q.push(node->right);
            }
        }
        q.push(target);
        vis[target] = 1;
        int curr_lvl = 0;
        while(!q.empty()){
            int size = q.size();
            if(curr_lvl++ == k) break;
            while(size--){
                TreeNode*node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left] = 1;
                }
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right] = 1; 
                }
                if(parent_track[node] && !vis[parent_track[node]]){
                    q.push(parent_track[node]);
                    vis[parent_track[node]] = 1;
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};