class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x = 0;
        for(auto val : nums) x ^= val;
        int a = x ^ k;
        return __builtin_popcount(a);
    }
};