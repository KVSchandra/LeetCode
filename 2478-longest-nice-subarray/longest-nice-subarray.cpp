class Solution {
public:
    void purify(vector<int>&v, int num) {
        for(int i = 0; i<32; i++) {
            if(num & (1 << i)) {
                v[i]--;
            }
        }
    }

    bool isGood(vector<int>&v) {
        for(auto val : v) {
            if(val > 1) return false;
        }
        return true;
    }

    int longestNiceSubarray(vector<int>& nums) {
        vector<int>v(32);
        int i = 0, j = 0;
        int maxi = INT_MIN;
        while(j < nums.size()) {
            for(int k = 0; k<32; k++) {
                if(nums[j] & (1 << k)) {
                    v[k]++;
                }
            }
            if(isGood(v)) {
                maxi = max(maxi, j-i+1);
                j++;
            }
            else {
                while(!isGood(v) && i <= j) {
                    purify(v, nums[i]);
                    i++;
                }
                j++;
            }
        }
        return maxi;
    }
};