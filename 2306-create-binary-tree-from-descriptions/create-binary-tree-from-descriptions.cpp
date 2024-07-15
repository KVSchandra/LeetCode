class Solution {
public:
    void dfs(int i, TreeNode* temp, vector<pair<int, int>> adj[]) {
        for(auto val : adj[i]) {
            if(val.second == 1) {
                temp->left = new TreeNode(val.first);
                dfs(val.first, temp->left, adj);
            }
            else {
                temp->right = new TreeNode(val.first);
                dfs(val.first, temp->right, adj);
            }
        }
    }

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        vector<pair<int, int>> adj[100001];
        map<int, int> mp;
        for(auto val : descriptions) {
            adj[val[0]].push_back({val[1], val[2]});
            mp[val[1]]++;
        }
        int x = -1;
        for(auto val : descriptions) {
            if(mp.find(val[0]) == mp.end()) {
                x = val[0];
                break;
            }
        }
        if(x == -1) return nullptr;
        TreeNode* root = new TreeNode(x);
        dfs(x, root, adj);
        return root;
    }
};