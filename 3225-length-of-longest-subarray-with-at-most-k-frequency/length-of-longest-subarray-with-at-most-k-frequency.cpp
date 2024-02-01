class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        unordered_map<int, int>mp;
        int maxi = INT_MIN;
        int maxFreq = INT_MIN;
        while(j < n){
            mp[nums[j]]++;
            // maxFreq = max(maxFreq, mp[nums[j]]);
            while(mp[nums[j]] > k){
                mp[nums[i]]--;
                i++;
            }
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};