class Solution {
public:
    void solve(int i, int prevInd, int &n, vector<int>&nums, vector<int>&ans, vector<int>&temp, vector<int>&dp) {
        if(i >= n) {
            if(temp.size() > ans.size()) ans = temp;
            return;
        }
        if((prevInd == -1 || nums[i] % nums[prevInd] == 0) && ((int)temp.size() > dp[i])) {
            dp[i] = temp.size();
            temp.push_back(nums[i]);
            solve(i+1, i, n, nums, ans, temp, dp);
            temp.pop_back();
        }
        solve(i+1, prevInd, n, nums, ans, temp, dp);
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        vector<int>temp;
        vector<int>dp(n+1, -1);
        solve(0, -1, n, nums, ans, temp, dp);
        return ans;
    }
};