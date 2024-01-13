class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int>mp;
        for(auto val : s) mp[val]++;  
        for(auto val : t) {
            if(val) mp[val]--;
        }
        int count = 0;
        for(auto val : mp){
            count += abs(val.second);
        }
        return count/2;
    }
};