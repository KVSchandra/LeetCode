class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(k == 0) return nums[0];
        if(nums.size() == 1 && k&1) return -1;
        int i = 0;
        int maxi = INT_MIN;
        while(i < nums.size() && i < k-1) {
            maxi = max(maxi, nums[i]);
            i++;
        }
        int a = INT_MIN;
        if(k < nums.size()) a = nums[k];
        return max(maxi, a);
    }
};