class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        unordered_map<int, int>mp;
        for(auto val : rectangles) {
            mp[min(val[0], val[1])]++;
        }
        int maxi = INT_MIN;
        int ans = 0;
        for(auto val : mp) {
            if(maxi < val.first) {
                maxi = val.first;
                ans = val.second;
            }
        }
        return ans;
    }
};