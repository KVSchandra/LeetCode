class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mini1 = INT_MAX, mini2 = INT_MAX;
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] <= mini1) {
                mini1 = nums[i];
            }
            else if(nums[i] <= mini2) {
                mini2 = nums[i];
            }
            else return true;
        }
        return false;
    }
};