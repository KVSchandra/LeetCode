class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int low = 1, high = n-2;
        bool flag = false;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                flag = true;
                return mid;
            }
            if(nums[mid] >= nums[mid-1] && nums[mid] <= nums[mid+1]) {
                low = mid + 1;
            }
            else high = mid - 1;
        }
        if(flag == false) {
            if(nums[0] > nums[1]) return 0;
            else if(nums[n-1] > nums[n-2]) return n-1;
        }
        return -1;
    }
};