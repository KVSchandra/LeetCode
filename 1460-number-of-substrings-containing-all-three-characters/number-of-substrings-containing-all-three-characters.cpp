class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        unordered_map<char, int>mp;
        int count = 0;
        int ans = 0;
        while(j < n){
            mp[s[j]]++;
            while(mp['a']>=1 && mp['b']>=1 && mp['c']>=1){
                ans += n-j;
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};