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
    pair<TreeNode*, TreeNode*> p;
    void getNodes(TreeNode* root, int a, int b) {
        if(root == NULL) return;
        getNodes(root->left, a, b);
        if(root->val == a) {
            p.first = root;
        }
        else if(root->val == b) {
            p.second = root;
        }
        getNodes(root->right, a, b);
    }

    TreeNode* lca(TreeNode* root, TreeNode* u, TreeNode* v) {
        if(root == NULL || root == u || root == v) return root;
        TreeNode* left = lca(root->left, u, v);
        TreeNode* right = lca(root->right, u, v);
        if(left == NULL) return right;
        if(right == NULL) return left;
        return root;
    }
    string ans = "";
    void solve(TreeNode* root, string &temp, int target) {
        if(root->val == target) {
            ans = temp;
            return;
        }
        if(root->left) {
            temp.push_back('L');
            solve(root->left, temp, target);
            temp.pop_back();
        }
        if(root->right) {
            temp.push_back('R');
            solve(root->right, temp, target);
            temp.pop_back();
        }
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        getNodes(root, startValue, destValue);
        TreeNode*a = p.first;
        TreeNode*b = p.second;
        TreeNode*v = lca(root, a, b);
        string s1 = "", s2 = "";
        solve(v, s1, a->val);
        s1 = ans;
        solve(v, s2, b->val);
        s2 = ans;
        for(auto &val : s1) val = 'U';
        s1 = s1 + s2;
        return s1;
    }
};