class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int>mp;
        int maxi = INT_MIN, count = 0;
        for(auto val : nums) mp[val]++;
        for(auto val : mp){
            maxi = max(val.second, maxi);
        }
        for(auto val : mp){
            if(val.second == maxi) count+=maxi;
        }
        return count;
    }
};