class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long prod = 1;
        long long count = 0;
        long long maxi = INT_MIN;
        bool flag = false;
        long long n = nums.size();
        long long c = 0;
        for(auto val : nums){
            if(val == 0) {flag = 1;c++;}
            if(val != 0) prod *= val;
            if(val < 0) {
                if(maxi < val){
                    maxi = val;
                }
                count++;
            }
        }
        if(n == 1 && flag == false && count == 1) return nums[0];
        if((flag && count == 1 && n == c + count) || (n == 1 && flag) || (c == n)) return 0;
        if(count & 1){
            prod /= maxi;
        }
        return prod;
    }
};