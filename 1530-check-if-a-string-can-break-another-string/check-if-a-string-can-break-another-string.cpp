class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int i = 0;
        while(s1[i] == s2[i]) i++;
        if(s1[i] >= s2[i]) {
            for(int j = i; j<s1.size(); j++) {
                if(s1[j] < s2[j]) return false;
                }
            }
        else if(s1[i] <= s2[i]){
            for(int j = i; j<s1.size(); j++) {
                if(s1[j] > s2[j]) return false;
            }
        }
        return true;
    }
};