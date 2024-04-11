class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for(int i = 0; i<s.size(); i++) {
            unordered_map<char, int> mp;
            for(int j = i; j<s.size(); j++) {
                mp[s[j]]++;
                 int mini = INT_MAX;
                 int maxi = INT_MIN;
                for(auto val : mp) {
                    maxi = max(maxi, val.second);
                    mini = min(mini, val.second);
                }
                ans += maxi - mini;
            }
        }
        return ans;
    }
};