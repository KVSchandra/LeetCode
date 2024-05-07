class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int>mp;
        for(auto val : s) mp[val]++;
        int k = repeatLimit;
        sort(s.begin(), s.end());
        vector<char>v;
        for(int i = 0; i<s.size()-1; i++) {
            if(s[i] != s[i+1]) v.push_back(s[i]);
        }
        if(v.size() && v.back() != s.back()) v.push_back(s.back());
        else v.push_back(s[0]);
        string ans = "";
        // for(auto val : v) cout << val << " ";
        while(v.size() >= 2) {
            if(mp[v.back()] == 0) {v.pop_back(); repeatLimit = k;}
            if(v.size() == 1) break;
            if(mp[v[v.size()-2]] == 0) {
                v.erase(v.begin()+v.size()-2);
            }
            if(v.size() == 1) break;
            if(repeatLimit) {
                ans += v.back();
                mp[v.back()]--;
                repeatLimit--;
            }
            else {
                ans.push_back(v[v.size()-2]);
                mp[v[v.size()-2]]--;
                repeatLimit = k;
            }
        }
        repeatLimit = k;
        while(mp[v.back()]-- && repeatLimit--) {
            ans += v.back();
        }
        return ans;
    }
};