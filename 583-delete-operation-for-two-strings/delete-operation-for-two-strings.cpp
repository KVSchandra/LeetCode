#define ll long long
class Solution {
public:
    int minDistance(string word1, string word2) {
        ll n = word1.size(), m = word2.size();
        vector<vector<ll>> dp(n+1, vector<ll>(m+1));
        for(ll i = n-1; i >= 0; i--) {
            for(ll j = m-1; j >= 0; j--) {
                if(word1[i] == word2[j]) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i+1][j+1]);
                }
                else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return (n + m - 2*dp[0][0]);
    }
};