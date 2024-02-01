class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int>mp;
        vector<string>ans;
        if(s.size() < 10) return ans;
        for(int i = 0; i<s.size()-9; i++){
            string a = s.substr(i, 10);
            mp[a]++;
        }
        for(auto val : mp){
            if(val.second > 1){
                ans.push_back(val.first);
            }
        }
        return ans;
    }
};