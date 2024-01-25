class Solution {
public:
    int partitionString(string s) {
        int count = 0;
        unordered_map<char, int>mp;
        for(int i = 0; i<s.size(); i++){
            if(mp.find(s[i]) != mp.end()){
                count++;
                mp.clear();
            }
            mp[s[i]]++;
        }
        return count + 1;
    }
};