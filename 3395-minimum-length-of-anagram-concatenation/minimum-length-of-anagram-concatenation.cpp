class Solution {
public:
    int minAnagramLength(string s) {
        for(int i = 1; i<=s.size(); i++) {
            if(s.size()%i == 0) {
                unordered_map<char, int>mp;
                for(int j = 0; j<i; j++) {
                    mp[s[j]]++;
                }
                int k = 0;
                int len = i;
                bool flag = false;
                while(k < s.size()) {
                    unordered_map<char, int>mp1;
                    string str = s.substr(k, len);
                    for(auto val : str) mp1[val]++;
                    for(auto val : str) {if(mp1[val] != mp[val]) {flag = true; break;}}
                    k += len;
                }
                if(k == s.size() && flag == false) return i;
            }
        }
        return s.size();
    }
};