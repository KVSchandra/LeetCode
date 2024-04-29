class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        unordered_map<int, int>mp;
        for(auto val : candidates) {
            for(int i = 0; i < 32; i++) {
                if(val & (1 << i)) {
                    mp[i]++;
                }
            }
        } 
        int maxi = INT_MIN;
        for(auto val : mp) {
            maxi = max(maxi, val.second);
        }
        return maxi;
    }
};