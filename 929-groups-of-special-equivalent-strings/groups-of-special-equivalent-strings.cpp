class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_map<string, int>mp;
        for(auto val : words) {
            string s1 = "", s2 = "";
            for(int i = 0; i<val.size(); i++) {
                if(i&1) s1.push_back(val[i]);
                else s2.push_back(val[i]);
            }
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
            string s = s1 + s2;
            mp[s]++;
        }
        return mp.size();
    }
};