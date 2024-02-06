class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string, vector<string>>mp;
        for(auto val : strs){
            string a = val;
            sort(val.begin(), val.end());
            mp[val].push_back(a);
        }
        for(auto val : mp){
            ans.push_back(val.second);
        }
        // sort(strs.begin(), strs.end());
        // for(auto val : strs) cout<<val<<" ";
        // cout<<endl;
        return ans;
    }
};