
class Solution {
public:
    void recur(int idx, set<vector<int>>& ans, vector<int>& temp, vector<bool>& vis, int sum, int k, int n) {
        if(k == 0) {
            if(sum == n) {
                ans.insert(temp);
            }
            return;
        }
        for(int i = idx; i <= 9; i++) {
            if(!vis[i]) {
                temp.push_back(i);
                vis[i] = 1;
                recur(i+1, ans, temp, vis, sum + i, k - 1, n);
                temp.pop_back();
                vis[i] = 0;
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>> ans;
        vector<int> temp;
        vector<bool> vis(10, 0);
        recur(1, ans, temp, vis, 0, k, n);
        vector<vector<int>>res(ans.begin(), ans.end());
        return res;
    }
};
