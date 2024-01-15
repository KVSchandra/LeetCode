class Solution {
public:
    int solve(int i, int x, int n, vector<int>&nums){
        if(i == n) return x;
        int pick = solve(i+1, x^nums[i], n, nums);
        int notPick = solve(i+1, x, n, nums);
        return pick + notPick;
    }

    int subsetXORSum(vector<int>& nums) {
        int x = 0;
        int n = nums.size();
        return solve(0, x, n, nums);
    }
};