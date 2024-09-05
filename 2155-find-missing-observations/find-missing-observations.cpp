#define ll long long
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans;
        ll sum = accumulate(rolls.begin(), rolls.end(), 0ll);
        ll a = (ll)mean * (n + rolls.size()) - sum;
        if(a < n || a > 6ll * n) return {};
        ll N = n;
        while(N--) {
            ans.push_back(a / n);
        }
        ll k = a % n;
        for(ll i = 0; i < k; i++) {
            ans[i]++;
        }
        return ans;
    }
};