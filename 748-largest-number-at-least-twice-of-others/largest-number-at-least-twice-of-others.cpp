class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<int>a = nums;
        sort(nums.begin(), nums.end());
        if (nums[nums.size()-1] >= 2*nums[nums.size()-2]) return find(a.begin(), a.end(), nums[nums.size()-1])-a.begin();
        return -1;
    }
};