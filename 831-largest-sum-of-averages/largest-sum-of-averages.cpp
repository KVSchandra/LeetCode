#define ll long long

class Solution {
public:
    double solve(ll i, ll k, vector<ll>& prefix, vector<vector<double>>& dp) {
        if(i == prefix.size()) {
            return (k == 0) ? 0 : INT_MIN;
        }
        if(dp[i][k] != -1) return dp[i][k];
        if(k == 0) return INT_MIN;
        double maxi = INT_MIN;
        for(ll j = i; j < prefix.size(); j++) {
            double temp = double(prefix[j] - (i > 0 ? prefix[i - 1] : 0)) / (j - i + 1);
            maxi = max(maxi, temp + solve(j + 1, k - 1, prefix, dp));
        }
        return dp[i][k] = maxi;
    }

    double largestSumOfAverages(vector<int>& nums, int k) {
        vector<ll> prefix(nums.size());
        vector<vector<double>> dp(nums.size() + 1, vector<double>(k + 1, -1));
        prefix[0] = nums[0];
        for(ll i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        return solve(0, k, prefix, dp);
    }
};
