class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int>v(32, 0);
        for(auto val : nums) {
            for(int i = 0; i<32; i++) {
                if(val & (1 << i)) {
                    v[i]++;
                }
            }
        }
        int count = 0;
        for(auto val : nums) {
            for(int i = 0; i<32; i++) {
                if(val & (1 << i)) {
                    count += nums.size() - v[i];
                }
                else {
                    count += v[i];
                }
            }
        }
        return count/2;
    }
};