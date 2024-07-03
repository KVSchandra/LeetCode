#define ll long long
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<ll> prefix(nums.size());
        prefix[0] = nums[0];
        for(ll i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }
        ll count = 0;
        for(ll i = 0; i < nums.size()-1; i++) {
            if(prefix[i] >= prefix.back() - prefix[i]) {
                count++;
            }   
        }
        return count;
    }
};