class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int a = 0, b = 0;
        if(nums1.size() & 1) {
            for(auto val : nums2) {
                a ^= val;
            } 
        }
        if(nums2.size() & 1) {
            for(auto val : nums1) {
                b ^= val;
            }
        }
        return a ^ b;
    }
};