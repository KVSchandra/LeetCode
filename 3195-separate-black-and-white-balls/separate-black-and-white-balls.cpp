#define ll long long
class Solution {
public:
    long long minimumSteps(string s) {
        ll count = 0, ans = 0;
        for(ll i = 0; i < s.size(); i++) {
            if(s[i] == '0') {
                ans += count;
            }
            else {
                count++;
            }
        }
        return ans;
    }
};