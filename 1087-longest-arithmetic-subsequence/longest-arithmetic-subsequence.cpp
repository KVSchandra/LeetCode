class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;

        vector<vector<int>> dp(n, vector<int>(n, 2));
        int maxi = 2;

        for(int j = 1; j < n; ++j) {
            for(int i = 0; i < j; ++i) {
                int diff = nums[j] - nums[i];
                int len = 2;

                for(int k = i - 1; k >= 0; --k) {
                    if(nums[i] - nums[k] == diff) {
                        len = max(len, dp[k][i] + 1);
                    }
                }

                dp[i][j] = len;
                maxi = max(maxi, len);
            }
        }

        return maxi;
    }
};
