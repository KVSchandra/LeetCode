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
    bool isEvenOddTree(TreeNode* root) {
        if(root == NULL) return true;
        int count = 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>v;
            while(size--){
                TreeNode*temp = q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                if((count%2 == 0 && (temp->val)%2 == 0) || (count%2 == 1 && (temp->val)%2 == 1)) return false;
                v.push_back(temp->val);
            }
            if(count%2 == 0){
                for(int i = 0; i<v.size()-1; i++){
                    if(v[i] >= v[i+1]) return false;
                }
            }
            else {
                for(int i = 0; i<v.size()-1; i++){
                    if(v[i] <= v[i+1]) return false;
                }
            }
            count++;
        }
        return true;
    }
};