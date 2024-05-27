class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<long long, long long>mp;
        for(auto val : nums1) {
            for(long long i = 1; i*i <= val; i++) {
                if(val%i == 0) {
                    mp[i]++;
                    if(val/i != i) mp[val/i]++;
                }
            }
        }
        long long count = 0;
        for(auto val : nums2) {
            if(mp[val*k]) count+=mp[val*k];
        }
        return count;
    }
};