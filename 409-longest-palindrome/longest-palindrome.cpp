class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int>mp;
        for(auto val : s) mp[val]++;
        int count = 0;
        int c = 0;
        for(auto val : mp) {
            if(val.second & 1) {
                c++;
                count += (val.second - 1);
            }
            else {
                count += val.second;
            }
        }
        if(c) count++;
        return count;
    }
};