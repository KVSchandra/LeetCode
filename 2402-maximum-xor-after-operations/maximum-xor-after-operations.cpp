class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans = 0;
        for(auto val : nums) ans |= val;
        return ans;
    }
};