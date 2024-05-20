class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k) return false;
        unordered_map<char, int>mp;
        for(auto val : s) {
            mp[val]++;
        }
        int odd = 0;
        for(auto val : mp) {
            if(val.second&1) odd++;
        }
        if(odd > k) return false;
        return true;
    }
};