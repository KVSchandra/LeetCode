#define ll long long
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        ll count = 0;
        ll ans = 0;
        for(ll i = 0; i < prices.size()-1; i++) {
            if(prices[i] == prices[i+1]+1) {
                count++;
            }
            else {
                ans += ((count)*(count+1))/2;
                count = 0;
            }
        }
        ans += ((count)*(count+1))/2;
        return ans + prices.size();
    }
};