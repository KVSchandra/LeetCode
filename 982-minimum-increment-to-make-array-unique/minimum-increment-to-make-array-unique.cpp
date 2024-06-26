class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] <= nums[i-1]) {
                count += abs(nums[i] - nums[i-1]) + 1;
                nums[i] += abs(nums[i] - nums[i-1]) + 1;
            }
        }
        // for(auto val : nums) cout << val << " ";
        return count;
    }
};