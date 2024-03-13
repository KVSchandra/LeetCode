class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 3) return 0;
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        sort(nums.begin(), nums.end(), greater<int>());
        int a = nums[3] - mini;
        int b = maxi - nums[nums.size()-4];
        int c = nums[1] - nums[nums.size()-3];
        int d = nums[2] - nums[nums.size()-2];
        return min(min(a, b), min(c, d));
    }
};