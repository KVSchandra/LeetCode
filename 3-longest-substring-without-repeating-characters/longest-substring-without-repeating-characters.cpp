class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0; 
        int j = 0;
        unordered_map<char, int>mp;
        int count = 0;
        int maxi = 0;
        while(j < n){
            mp[s[j]]++;
            if(mp[s[j]] == 1){
                maxi = max(j-i+1, maxi);
            }
            while(mp[s[j]] > 1){
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return maxi;
    }
};