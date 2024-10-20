#define ll long long
class Solution {
public:
    // NEED TO FIND THE LONGEST PALINDROME FROM THE GIVEN STRING
    int minInsertions(string s) {
        ll n = s.size();
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;
        vector<vector<ll>> dp(n+1, vector<ll>(n+1));
        for(ll i = n - 1; i >= 0; i--) {
            for(ll j = n - 1; j >= 0; j--) {
                if(s1[i] == s2[j]) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i+1][j+1]);
                }
                else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return (n - dp[0][0]);
    }
};