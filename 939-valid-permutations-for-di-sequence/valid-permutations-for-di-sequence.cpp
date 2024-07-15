#define ll long long
const ll mod = 1e9+7;
class Solution {
public:
    vector<ll> vis;
    vector<vector<ll>> dp;
    ll solve(ll i, ll prev, string& s) {
        if(i == s.size()) return 1;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int ans = 0;
        for(ll j = 0; j < s.size()+1; j++) {
            if(vis[j]) continue;
            if(prev == -1) {
                vis[j] = 1;
                ans = (ans + solve(i, j, s)) % mod;
                vis[j] = 0;
            }
            else {
                if(s[i] == 'D') {
                    if(j < prev) {
                        vis[j] = 1;
                        ans = (ans + solve(i+1, j, s)) % mod;
                        vis[j] = 0;
                    }
                }
                else {
                    if(j > prev) {
                        vis[j] = 1;
                        ans = (ans + solve(i+1, j, s)) % mod;
                        vis[j] = 0;
                    }
                }
            }
        }
        return dp[i][prev+1] = ans;
    }

    int numPermsDISequence(string s) {
        vis.resize(s.size()+2);
        dp.resize(s.size()+2, vector<ll> (s.size()+4, -1));
        return solve(0, -1, s);
    }
};