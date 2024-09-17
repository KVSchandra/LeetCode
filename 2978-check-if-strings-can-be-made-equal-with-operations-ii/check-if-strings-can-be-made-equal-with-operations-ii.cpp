class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char, int> mp1, mp2;
        for(int i = 0; i < s1.size(); i++) {
            if(i & 1) {
                mp1[s1[i]]++;
                mp1[s2[i]]--;
            }
            else {
                mp2[s1[i]]++;
                mp2[s2[i]]--;
            }
        }
        for(auto val : mp1)  {
            if(val.second != 0) return false;
        }
        for(auto val : mp2) {
            if(val.second != 0) return false;
        }
        return true;
    }
};