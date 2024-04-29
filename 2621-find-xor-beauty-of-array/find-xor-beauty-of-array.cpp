class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        long long x = 0;
        if(nums.size() <= 1) return nums[0];
        for(auto val : nums) {
            x ^= val;
        }
        return x;
    }
};