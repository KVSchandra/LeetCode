class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() <= 2) return nums;
        int x = nums[0];
        for(int i = 1; i<nums.size(); i++) {
            x ^= nums[i];
        }
        int a;
        for(int i = 0; i<32; i++) {
            if(x & (1 << i)) {
                a = i;
                break;
            }
        }
        int X;
        int count = 0;
        for(int i = 0; i<nums.size(); i++){
            if((nums[i] & (1 << a)) == 0) {
                if(count == 0) {
                    X = nums[i];
                    count++;
                }
                else {
                    X ^= nums[i];
                }
            }
        }
        int b = X ^ x;
        return {X, b};
    }
};