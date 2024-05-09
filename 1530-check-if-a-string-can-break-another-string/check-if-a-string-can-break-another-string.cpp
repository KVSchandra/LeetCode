class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if(s1[0] > s2[0]) {
            for(int i = 1; i<s1.size(); i++) {
                if(s1[i] < s2[i]) return false;
            }
        }
        else if(s1[0] < s2[0]){
            for(int i = 1; i<s1.size(); i++) {
                if(s1[i] > s2[i]) return false;
            }
        }
        else {
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
        }
        return true;
    }
};