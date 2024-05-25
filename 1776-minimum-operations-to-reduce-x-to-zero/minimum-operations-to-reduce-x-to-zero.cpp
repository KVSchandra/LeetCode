class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int maxi = -1;
        int i = 0, j = 0;
        int k = accumulate(nums.begin(), nums.end(), 0) - x;
        long long sum = 0;
        while(j < nums.size()) {
            sum += nums[j];
            if(sum < k) {
                j++;
            }
            else {
                while(sum >= k && i <= j) {
                    if(sum == k) {
                        maxi = max(maxi, j-i+1);
                    }
                    sum -= nums[i];
                    i++;
                }
                j++;
            }
        }
        if(sum == k) return nums.size();
        if(maxi == -1) return -1;
        return nums.size()-maxi;
    }
};