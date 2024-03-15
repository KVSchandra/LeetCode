class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long>ans(nums.size());
        long long maxi = nums[0];
        ans[0] = 2*nums[0];
        for(int i = 1; i<nums.size(); i++){
            maxi = max((long long)maxi, (long long)nums[i]);
            ans[i] = nums[i] + maxi;
            ans[i] += ans[i-1];
        }
        return ans;
    }
};
