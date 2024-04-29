class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans(nums.size(), 0);
        int k = maximumBit;
        int x = 0;
        for(auto val : nums) {
            x ^= val;
        }
        int count = 0;
        while(nums.size()) {
            int a = 0;
            for(int i = 0; i<k; i++) {
                if((x & (1 << i)) == 0) {
                    a |= (1 << i);
                }
            }
            ans[count] = a;
            x ^= nums.back();
            nums.pop_back();
            count++;
        }
        return ans;
    }
};