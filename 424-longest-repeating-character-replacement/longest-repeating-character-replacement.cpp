class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int>mp;
        int i = 0;
        int j = 0;
        int maxi = 0;
        int maxFreq = 0;
        while(j < n){
            mp[s[j]]++;
            maxFreq = max(maxFreq, mp[s[j]]);
            while(j-i+1 - maxFreq > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};