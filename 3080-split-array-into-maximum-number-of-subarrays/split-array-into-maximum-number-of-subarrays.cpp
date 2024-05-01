class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int x = nums[0];
        for(int i = 1; i<nums.size(); i++) {
            x &= nums[i];
        }
        if(x) return 1;
        int mini = INT_MAX;
        int count = 0;
        for(auto val : nums) {
            mini &= val;
            if(mini == 0) {
                count++;
                mini = INT_MAX;
            }
        }
        return count;
    }
};