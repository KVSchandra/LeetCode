class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        long long ans = INT_MIN;
        int maxi = INT_MIN, mini = INT_MAX;
        for(auto val : arrays) {
            if(maxi != INT_MIN) {
                ans = max(ans, abs((long long)maxi - val[0]));
            }
            if(mini != INT_MAX) {
                ans = max(ans, abs((long long)val.back() - mini));
            }
            maxi = max(maxi, val.back());
            mini = min(mini, val[0]);
        }
        return ans;
    }
};