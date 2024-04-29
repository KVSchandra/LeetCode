class Solution {
public:
    int solve(int i, int mask, vector<int> &nums) {
        if(mask == (1 << nums.size())-1) return 1;
        int count = 0;
        for(int j = 0; j<nums.size(); j++) {
            if(((mask & (1 << j)) == 0) && (nums[j]%i == 0 || i % nums[j] == 0)) {
                mask |= (1 << j);
                count += solve(i+1, mask, nums);
                mask &= ~(1 << j);
            }
        }
        return count;
    }

    int countArrangement(int n) {
        vector<int>nums;
        for(int i = 0; i<n; i++) {
            nums.push_back(i+1);
        }
        int mask = 0;
        return solve(1, mask, nums);
    }
};