class Solution {
public:
    void solve(int i, int prevInd, vector<int>&output, vector<vector<int>>&ans, vector<int>&nums){
        if(i == nums.size()){
            if(output.size() > 1)
            ans.push_back(output);
            return;
        }
        if(prevInd == -1 || nums[prevInd] <= nums[i]){
            output.push_back(nums[i]);
            solve(i+1, i, output, ans, nums);
            output.pop_back();
        }
        solve(i+1, prevInd, output, ans, nums);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        set<vector<int>>st;
        solve(0, -1, output, ans, nums);
        for(auto val : ans) st.insert(val);
        ans.clear();
        for(auto val : st) ans.push_back(val);
        return ans;
    }
};