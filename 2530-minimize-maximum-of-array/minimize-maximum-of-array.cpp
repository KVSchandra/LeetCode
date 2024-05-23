class Solution {
public:
    bool solve(long long mid, vector<int>&nums) {
        long long last = nums[0];
        if(last > mid) return false;
        for(long long i = 1; i<nums.size(); i++) {
            last = nums[i] - (mid - last);
            if(last > mid) return false;
            // if(last < 0) last = 0;
        }
        return true;
    }

    int minimizeArrayValue(vector<int>& nums) {
        long long low = 0;
        long long high = *max_element(nums.begin(), nums.end());
        // if(low == high) return low;
        while(low <= high) {
            long long mid = low + (high - low)/2;
            if(solve((long long)mid, nums)) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};