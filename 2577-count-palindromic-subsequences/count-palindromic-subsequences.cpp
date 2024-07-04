#define ll long long
const ll mod = 1e9+7;

class Solution {
public:
    ll dp[10000][10][10][6];

    ll solve(ll i, ll first, ll second, ll count, string& s) {
        if(i == s.size()) {
            return (count == 5);
        }
        if(dp[i][first][second][count] != -1) return dp[i][first][second][count];
        ll pick = 0;
        if(count == 0) {
            pick = (pick + solve(i+1, s[i]-'0', second, count+1, s)) % mod;
        }
        else if(count == 1) {
            pick = (pick + solve(i+1, first, s[i]-'0', count+1, s)) % mod;
        }
        else if(count == 2) {
            pick = (pick + solve(i+1, first, second, count+1, s)) % mod;
        }
        else if(count == 3) {
            if(s[i]-'0' == second) pick = (pick + solve(i+1, first, second, count+1, s)) % mod;
        }
        else if(count == 4) {
            if(s[i]-'0' == first) pick = (pick + solve(i+1, first, second, count+1, s)) % mod;
        }
        ll notPick = solve(i+1, first, second, count, s);
        return dp[i][first][second][count] = (pick + notPick) % mod;
    }

    int countPalindromes(string s) {
        ll n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, 0, s);
    }   
};