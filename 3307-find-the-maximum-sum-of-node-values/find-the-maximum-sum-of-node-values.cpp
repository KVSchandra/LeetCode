class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0;
        long long count = 0, mini = INT_MAX;
        for(int i = 0; i<nums.size(); i++) {
            if((nums[i]^k) > nums[i]) {
                sum += nums[i]^k;
                count++;
            }
            else sum += nums[i];
            mini = min(mini, (long long)abs((nums[i]^k) - nums[i]));
        }
        if((count&1) == 0) return sum;
        return sum - mini;
    }
};