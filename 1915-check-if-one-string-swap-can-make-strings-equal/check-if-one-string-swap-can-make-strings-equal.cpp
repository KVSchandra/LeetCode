class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0;
        if(s1 == s2) return true;
        unordered_map<char, int>mp;
        for(auto val : s1) mp[val]++;
        for(auto val : s2) mp[val]--;
        for(auto val : mp) if(val.second != 0) return false;
        for(int i = 0; i<s1.size(); i++){
            if(s1[i] != s2[i]) count++;
        }
        if(count == 2) return true;
        return false;
    }
};