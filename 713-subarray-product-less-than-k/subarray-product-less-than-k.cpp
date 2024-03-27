class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int i = 0, j = 0;
        int prod = 1;
        while(j < n) {
            prod *= nums[j];
            if(prod >= k) {
                while(prod >= k && i < j) {
                    prod /= nums[i];
                    i++;
                }
            }
            if(prod < k) count += (j-i+1);
            j++;
        }
        return count;
    }
};