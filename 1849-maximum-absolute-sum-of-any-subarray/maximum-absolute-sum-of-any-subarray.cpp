class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int n = nums.size();
        int minSum = 0;
        int maxSum = 0;
        for(int i = 0;i<n;i++){
            minSum += nums[i];
            maxSum += nums[i];
            if(maxi < maxSum) maxi = maxSum;
            if(mini > minSum) mini = minSum;
            if(maxSum < 0) maxSum = 0;
            if(minSum > 0) minSum = 0;
        }
        return max(maxi,abs(mini));
    }
};