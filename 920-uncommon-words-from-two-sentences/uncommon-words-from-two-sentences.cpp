class Solution {
public:
    void solve(string& s, map<string, int>& mp) {
        string temp = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                mp[temp]++;
                temp.clear();
            }
            else {
                temp.push_back(s[i]);
            }
        }
        mp[temp]++;
    }

    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string, int> mp1, mp2;
        solve(s1, mp1);
        solve(s2, mp2);
        vector<string> ans;
        for(auto val : mp1) {
            if(val.second == 1) {
                if(mp2.find(val.first) == mp2.end()) {
                    ans.push_back(val.first);
                }
            }
        }
        for(auto val : mp2) {
            if(val.second == 1) {
                if(mp1.find(val.first) == mp1.end()) {
                    ans.push_back(val.first);
                }
            }
        }
        return ans;
    }
};