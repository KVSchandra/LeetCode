class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, 0);
        vector<int>prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }
        for(int i = 0; i < n; i++) {
            int a = (i - n + i + 1)*nums[i];
            if(i-1 >= 0) a -= prefix[i-1];
            a += prefix.back() - prefix[i];
            ans[i] = a;
        }
        return ans;
    }
};