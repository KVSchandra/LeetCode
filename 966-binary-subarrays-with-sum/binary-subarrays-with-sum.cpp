class Solution {
public:
    int solve(vector<int>&nums, int goal){
        int n = nums.size();
        int i = 0;
        int j = 0;
        int count = 0;
        if(goal < 0) return 0;
        unordered_map<int, int>mp;
        long long sum = 0;
        while(j < n){
            sum += nums[j];
            while(sum > goal){
                sum -= nums[i];
                i++;
            }
            count += j-i+1;
            j++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal-1);
    }
};