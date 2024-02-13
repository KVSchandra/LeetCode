class Solution {
public:
    int mod = 1e9+7;

    int countHomogenous(string s) {
        int i = 0;
        int j = 0;
        unordered_map<char, int>mp;
        long long count = 0;
        while(j < s.size()){
            mp[s[j]]++;
            while(mp.size() > 1 && i<=j){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
            count += j-i+1;
            j++;
        }
        return (count)%mod;
    }
};