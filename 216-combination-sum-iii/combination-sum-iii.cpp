class Solution {
public:
    void solve(int i, int k, int n, vector<int>&output, vector<vector<int>>&ans, vector<int>&v){
        if(i == v.size()) {
            if(n == 0 && k == 0){
                ans.push_back(output);
            }
            return;
        }
        if(n == 0){
            if(k == 0) {
                ans.push_back(output);
            }
            return;
        }
        if(n - v[i] >= 0 && k){
            output.push_back(v[i]);
            solve(i+1, k-1, n-v[i], output, ans, v);
            output.pop_back();
        }
        solve(i+1, k, n, output, ans, v);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>output;
        vector<int>v;
        for(int i = 1; i<=9; i++){
            v.push_back(i);
        }
        solve(0, k, n, output, ans, v);
        return ans;
    }
};