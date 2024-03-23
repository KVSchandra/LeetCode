class Solution {
public:
    int solve(int mid, vector<int>&nums) {
        int ans = 0;
        for(int i = 0; i<nums.size(); i++) {
            ans += ceil((double)nums[i]/mid);
        }
        return ans;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = *max_element(nums.begin(), nums.end());
        int low = 1, high = maxi;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(solve(mid, nums) <= threshold) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};