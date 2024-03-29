class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long i = 0, j = 0;
        unordered_map<long long, long long>mp;
        long long count = 0;
        long long maxi = *max_element(nums.begin(), nums.end());
        while(j < nums.size()) {
            mp[nums[j]]++;
            if(mp[maxi] < k) {
                j++;
            }
            else if(mp[maxi] >= k) {
                while(mp[maxi] >= k) {
                    count += nums.size()-j;
                    mp[nums[i]]--;
                    i++;
                    // count += (nums.size()-1-i);
                }
                j++;
            }
        } 
        return count;
    }
};