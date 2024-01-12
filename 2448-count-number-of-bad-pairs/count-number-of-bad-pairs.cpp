class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<long long, long long>mp;
        long long n = nums.size();
        long long a = 0;
        for(int i = 0; i<n; i++){
            mp[nums[i] - i]++;
        }
        for(auto val : mp){
            a += (val.second*(val.second-1))/2;
        }
        long long sum = n*(n-1)/2;
        return sum - a;
    }
};