class Solution {
public:
    int count = -1;
    void solve(int i, int k, unordered_map<int, int>&mp, vector<int> &nums) {
        if(i == nums.size()) {
            count++;
            return;
        }
        if(mp[nums[i]+k] == 0 && mp[nums[i]-k] == 0) {
            mp[nums[i]]++;
            solve(i+1, k, mp, nums);
            mp[nums[i]]--;
        }
        solve(i+1, k, mp, nums);
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        solve(0, k, mp, nums);
        return count;
    }
};