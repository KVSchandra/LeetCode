class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k = *max_element(nums.begin(), nums.end());
        int maxi = INT_MIN;
        int count = 0;
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] == k) {
                count++;
            }
            else {
                maxi = max(maxi, count);
                count = 0;
            }
        }
        maxi = max(maxi, count);
        return maxi;
    }
};