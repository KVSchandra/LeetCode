class Solution {
public:
    int solve(int i, int x, int k, vector<int>&nums) {
        if(i == nums.size() && x == k) return 1;
        if(i == nums.size()) return 0;
        int pick = solve(i+1, (x | nums[i]), k, nums);
        int notPick = solve(i+1, x, k, nums);
        return pick + notPick;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int x = 0;
        for(auto val : nums) x |= val;
        return solve(0, 0, x, nums);
    }
};