#define ll long long
class Solution {
public:
    int mod = 1e9 + 7;
    ll solve(int i, int l, int e, int t, int n, vector<vector<vector<vector<ll>>>>&dp) {
        if(i == n) {
            if(e >= 2 && l >= 1 && t >= 1) return 1ll;
            return 0ll;
        }
        if(dp[i][l][e][t] != -1) return dp[i][l][e][t];
        ll pick = 0;
        for(ll j = 0; j<26; j++) {
            if(j == 4 && e < 2) {
                pick = (pick + solve(i+1, l, e+1, t, n, dp))%mod;
            }
            else if(j == 11 && l < 1) {
                pick = (pick + solve(i+1, l+1, e, t, n, dp))%mod;
            }
            else if(j == 19 && t < 1) {
                pick = (pick + solve(i+1, l, e, t+1, n, dp))%mod;
            }
            else pick = (pick + solve(i+1, l, e, t, n, dp))%mod;
        }
        return dp[i][l][e][t] = (pick)%mod;
    }

    int stringCount(int n) {
        vector<vector<vector<vector<ll>>>>dp(n+1, vector<vector<vector<ll>>>(2, vector<vector<ll>>(3, vector<ll>(2, -1))));
        return (int)solve(0, 0, 0, 0, n, dp)%mod;
    }
};