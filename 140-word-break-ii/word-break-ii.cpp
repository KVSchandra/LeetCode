class Solution {
public:
    void solve(int i, string &temp, string &s, unordered_map<string, int>&mp, vector<string>&ans) {
        if(i == s.size()) {
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        for(int j = i; j<s.size(); j++) {
            string a = s.substr(i, j-i+1);
            if(mp.find(a) != mp.end()) {
                string af = temp;
                temp += a;
                temp.push_back(' ');
                solve(j+1, temp, s, mp, ans);
                temp = af;
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>ans;
        unordered_map<string, int>mp;
        for(auto val : wordDict) mp[val]++;
        string temp = "";
        solve(0, temp, s, mp, ans);
        return ans;
    }
};