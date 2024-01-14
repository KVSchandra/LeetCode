class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int>mp;
        for(auto val : edges){
            mp[val[0]]++;
            mp[val[1]]++;
        }
        int maxi = INT_MIN;
        int ans;
        for(auto val : mp){
            if(maxi < val.second){
                maxi = val.second;
                ans = val.first;
            }
        }
        return ans;
    }
};