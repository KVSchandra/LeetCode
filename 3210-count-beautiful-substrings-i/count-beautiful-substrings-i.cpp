class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        vector<char>vow = {'a', 'e' ,'o', 'u', 'i'};
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            int v = 0, c = 0;
            for(int j = i; j<s.size(); j++) {
                if(find(vow.begin(), vow.end(), s[j]) != vow.end()) v++;
                else c++;
                if((v == c) && ((v*c)%k == 0)) count++;
            }
        }
        return count;
    }
};