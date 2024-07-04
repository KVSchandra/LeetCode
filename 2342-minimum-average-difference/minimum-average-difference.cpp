class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long mini = INT_MAX, ans = 0;
        vector<long long> prefix(nums.size());
        prefix[0] = nums[0];
        for(long long i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }
        for(long long i = 0; i < nums.size(); i++) {
            long long a = prefix[i]/(i+1);
            long long b = 0;
            if(i != nums.size()-1) {
                b = (prefix.back() - prefix[i]) / (nums.size()-i-1);
            }
            if(mini  > abs(a - b)) {
                mini = abs(a-b);
                ans = i;
            }
        }
        return ans;
    }
};