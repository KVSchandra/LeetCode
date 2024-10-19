#define ll long long
class Solution {
public:
    int rob(vector<int>& nums) {
        ll n = nums.size();
        vector<ll> dp(n+2, INT_MIN);
        dp[n] = 0;
        dp[n+1] = 0;
        for(ll i = n-1; i >= 0; i--) {
            dp[i] = max(dp[i], dp[i+1]);
            dp[i] = max(dp[i], nums[i] + dp[i+2]);
        }
        return dp[0];
    }
};