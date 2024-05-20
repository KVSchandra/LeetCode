#define ll long long
class Solution {
public:
    ll solve(ll i, bool prev, ll jump, ll k, unordered_map<ll, unordered_map<ll, unordered_map<ll, ll>>>& dp) {
        if(i > k + 1) return 0; 
        if(dp[i][jump].find(prev) != dp[i][jump].end()) return dp[i][jump][prev];
        ll pick1 = 0;
        if (prev == 0 && i - 1 >= 0) pick1 = solve(i - 1, 1, jump, k, dp);
        ll pick2 = solve(i + (1 << jump), 0, jump + 1, k, dp);
        ll ans = pick1 + pick2;
        if(i == k) ans++;
        return dp[i][jump][prev] = ans;
    }

    int waysToReachStair(int k) {
        unordered_map<ll, unordered_map<ll, unordered_map<ll, ll>>>dp;
        return solve(1, 0, 0, k, dp);
    }
};
