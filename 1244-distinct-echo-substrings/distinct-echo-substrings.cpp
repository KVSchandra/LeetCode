class Solution {
public:
    bool solve(string &s) {
        int i = 0, j = s.size()/2;
        while(j < s.size()) {
            if(s[i] != s[j]) return false;
            i++;
            j++;
        }
        return true;
    }

    int distinctEchoSubstrings(string text) {
        int count = 0;
        unordered_map<string, int>mp;
        for(int i = 0; i<text.size(); i++) {
            string temp = "";
            for(int j = i; j<text.size(); j++) {
                temp += text[j];
                if(temp.size()%2 == 0 && mp.find(temp) == mp.end()) {
                    if(solve(temp)) {count++; mp[temp]++;}
                }
            }
        }
        return count;
    }
};