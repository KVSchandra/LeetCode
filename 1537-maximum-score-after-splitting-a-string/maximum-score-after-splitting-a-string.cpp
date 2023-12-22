class Solution {
public:
    int maxScore(string s) {
        int one = 0, zero = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '1') one++;
        }
        int maxi = INT_MIN;
        for(int i = 0; i<s.size()-1; i++){
           
            if(s[i] == '1') one--;
            else zero++;
            maxi = max(maxi, one + zero);
        }
        return maxi;
    }
};