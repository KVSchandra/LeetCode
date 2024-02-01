class Solution {
public:
    long long solve(vector<int>&nums, int k){
        int n = nums.size();
        long long i = 0;
        long long j = 0;
        unordered_map<int, int>mp;
        long long maxi = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        while(j < n){
           if(nums[j] == maxi) mp[nums[j]]++;
            while(mp[maxi] >= k){
                ans += n-j;
                if(nums[i] == maxi){
                    mp[maxi]--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }

    long long countSubarrays(vector<int>& nums, int k) {
        return solve(nums, k);
    }
};