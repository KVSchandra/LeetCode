class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        unordered_map<char, int>mp;
        for(auto val : pattern) mp[val]++;
        for(int i = 0; i<words.size(); i++){
            int count1 = 0;
            unordered_map<char, int>mp1;
            for(auto val : words[i]){
                mp1[val]++;
            }
            if(words[i].size() != pattern.size()) continue;
            for(int j = 0; j<pattern.size()-1; j++){
                if(mp1[words[i][j]] != mp[pattern[j]]){
                    count1 = -20;
                    break;
                }
                if(words[i][j] == words[i][j+1]){
                    count1++;
                }
                if(pattern[j] == pattern[j+1]){
                    count1--;
                }
                if(count1 >= 1 || count1 <= -1) {
                    count1 = -20;
                    break;
                }
            }
            if(count1 != -20) ans.push_back(words[i]);
        }
        return ans;
    }
};