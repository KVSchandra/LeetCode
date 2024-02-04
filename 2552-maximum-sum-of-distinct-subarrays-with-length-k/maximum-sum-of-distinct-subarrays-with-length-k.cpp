class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        unordered_map<int, int>mp;
        long long sum = 0;
        // for(int a = 0; a<k; a++) sum += nums[a];
        long long maxi = INT_MIN;
        while(j < n){
            mp[nums[j]]++;
            sum += nums[j];
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                if(mp.size() == k){
                    if(maxi < sum) maxi = sum;
                }
                sum -= nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
                j++;
            }
            
        }
        if(maxi < 0) maxi = 0;
        return maxi;
    }
};