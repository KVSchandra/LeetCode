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
    int minimumOperations(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        while(!q.empty()) {
            int size = q.size();
            vector<int>temp;
            while(size--) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                temp.push_back(node->val);
                if(node->right) q.push(node->right);
            }
            vector<int>v = temp;
            sort(temp.begin(), temp.end());
            int cnt = 0;
            for(int i = 0; i<v.size(); i++) {
                if(v[i] != temp[i]) {
                    int idx = find(v.begin(), v.end(), temp[i]) - v.begin();
                    swap(v[i], v[idx]);
                    cnt++;
                }
            }
            count += cnt;
        }
        return count;
    }
};