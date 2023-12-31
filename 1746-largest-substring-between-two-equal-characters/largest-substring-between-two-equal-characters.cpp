class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        int maxi = INT_MIN;
        for(int i = 0; i<s.size(); i++){
            for(int j = i+1; j<s.size(); j++) {
                if(s[i] == s[j]) maxi = max(maxi, j-i-1);
            }
        }
        if(maxi == INT_MIN) return -1;
        return maxi;
    }
};