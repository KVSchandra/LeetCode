class Solution {
public:
    void solve(int i, int k, vector<int>&output, vector<vector<int>>&ans, vector<int>&candidates){
        if(i == candidates.size()){
            if(k == 0){
                ans.push_back(output);
            }
            return;
        }
        if(k == 0){
            ans.push_back(output);
            return;
        }
        //Take
        if(k - candidates[i] >= 0){
            output.push_back(candidates[i]);
            solve(i, k-candidates[i], output, ans, candidates);
            output.pop_back();
        }
        //NotTake
        solve(i+1, k, output, ans, candidates);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>output;
        solve(0, target, output, ans, candidates);
        return ans;
    }
};