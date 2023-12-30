class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int>mp;
        for(int i = 0; i<words.size(); i++) {
            for(int j = 0; j<words[i].size(); j++){
                mp[words[i][j]]++;
            }
        }
        for(auto val : mp) {
            if(val.second % (words.size()) != 0) return false;
        }
        return true;
    }
};