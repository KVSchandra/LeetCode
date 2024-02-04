class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        unordered_map<int, int>mp;
        long long sum = 0;
        long long maxi = 0;
        while(j < n){
            mp[nums[j]]++;
            sum += nums[j];
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                if(mp.size() >= m){
                    maxi = max(maxi, sum);
                }
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                sum -= nums[i];
                i++;
                j++;
            }
        }
        return maxi;
    }
};