class Solution {
public:
    void solve(int idx, vector<int>& candidates, int n, int sum, int target, vector<int>& temp,         vector<vector<int>>& ans) {
        if (sum == target) {
            ans.push_back(temp);
            return;
        }
        for (int i = idx; i < n; i++) {
            if (i != idx &&  candidates[i] == candidates[i-1])
                continue;
            if (sum + candidates[i] > target)
                break;    
            sum += candidates[i];
            temp.push_back(candidates[i]);
            solve(i+1, candidates, n, sum, target, temp, ans);
            sum -= candidates[i];
            temp.pop_back();    
        } 
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, n, 0, target, temp, ans);
        return ans;
    }
};