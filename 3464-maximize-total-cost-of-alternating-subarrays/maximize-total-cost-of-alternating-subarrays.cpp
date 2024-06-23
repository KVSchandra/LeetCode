#define ll long long
class Solution {
public:
    ll dp[100001][2];
    ll solve(ll i, vector<int>&nums, bool b) {
        if(i == nums.size()) return 0;
        if(dp[i][b] != -1) return dp[i][b];
        ll pick = 0;
        if(b == 0) {
            pick += nums[i] + solve(i+1, nums, !b);
        }
        else {
            pick += solve(i+1, nums, !b) - nums[i];
            pick = max(pick, nums[i] + solve(i+1, nums, b));
        }
        return dp[i][b] = pick;
    }
    
    long long maximumTotalCost(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, 0);
    }
};