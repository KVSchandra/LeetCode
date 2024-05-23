class Solution {
public:
    bool solve(int mid, vector<int>&nums, int k) {
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] > mid) {
                k -= ceil((double)nums[i]/mid) - 1;
                if(k < 0) return false;
            }
            i++;
        }
        if(k >= 0) return true;
        return false;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        sort(nums.begin(), nums.end());
        int low = 1;
        int high = nums.back();
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(solve(mid, nums, maxOperations)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};