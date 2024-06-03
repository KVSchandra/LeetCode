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
    void getParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track) {
        if(!root) {
            return;
        }
        if(root->left) {
            parent_track[root->left] = root;
            getParents(root->left, parent_track);
        }
        if(root->right) {
            parent_track[root->right] = root;
            getParents(root->right, parent_track);
        }
        
    } 

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>parent_track;
        getParents(root, parent_track);
        unordered_map<TreeNode*, bool> vis;
        // for(auto t : parent_track) {
        //     cout << t.first->val << " " << t.second->val << endl;
        // }
        queue<TreeNode*>q;
        q.push(target);
        vis[target] = 1;
        vector<int>ans;
        int count = -1;
        while(!q.empty()) {
            int size = q.size();
            count++;
            if(count == k) {
                break;
            }
            while(size--) {
                TreeNode* node = q.front();
                q.pop();
                if(node && node->left && !vis[node->left]) {q.push(node->left); vis[node->left] = 1;}
                if(node && node->right && !vis[node->right]) {q.push(node->right); vis[node->right] = 1;}
                if(node && !vis[parent_track[node]] && parent_track.find(node) != parent_track.end()) {q.push(parent_track[node]); vis[parent_track[node]] = 1;}
            }
        }
        while(count == k && !q.empty()) {
            TreeNode*temp = q.front();
            if(temp) {
                ans.push_back(temp->val);
            }
            q.pop();
        }
        return ans;
    }
};