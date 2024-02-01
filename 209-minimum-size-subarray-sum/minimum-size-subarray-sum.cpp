class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int i = 0, j = 0;
        int mini = INT_MAX;
        while(j < n){
            sum += nums[j];
            while(target <= sum && i <= j){
                sum -= nums[i];
                mini = min(mini, j-i+1);
                i++;
            }
            j++;
        }
        if(mini == INT_MAX) return 0;
        return mini;
    }
};